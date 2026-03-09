// COMSC-210 | Lab 19 | Barsbek
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

struct Review {
    double rating{};
    string comment{};
};

struct Node {
    Review value{};
    Node* next{};
};

class Movie {
private:
    string m_title{};
    Node* m_head{};
public:
    Movie() : m_title{""}, m_head{nullptr} {}
    ~Movie() { // frees memory
        Node* current = m_head;
        while (current) {
            m_head = current->next;
            delete current;
            current = m_head;
        }
        m_head = nullptr;
    }

    // Getter
    string getTitle() { return m_title; }
    // Setter
    void setTitle(const string& title) { m_title = title; }

    void addReview(const Review& review) {
        Node* newNode{new Node};
        newNode->value = review;
        newNode->next = m_head;
        m_head = newNode;
    }

    // calcs the avg rating of all reviews in the list
    double calcAvg() {
        double sum{};
        int count{0};

        Node* current = m_head;

        while (current) {
            sum += current->value.rating;
            current = current->next;
            ++count;
        }

        if (count == 0) return 0;

        return sum / count;
    }

    void printReviews() { // outputs and calcs avg of all reviews
        Node* current{m_head};
        int count{1};
        const double avg = calcAvg();
        cout << m_title << '\n';
        while (current) {
            cout << "\t > Review #" << count << ": "
                                    << current->value.rating << ": "
                                    << current->value.comment << '\n';
            current = current->next;
            ++count;
        }
        cout << fixed << setprecision(2)
             << "\t > Average rating: " << avg << '\n';
    }
};

int main() {
    srand(time(0));
    // min and max val for rnd
    const int MIN{10};
    const int MAX{50};

    vector<Movie> movieList{};
    Movie movieOne{};
    movieOne.setTitle("Attack On Titan");

    Movie movieTwo{};
    movieTwo.setTitle("Dan Da Dan");

    Movie movieThree{};
    movieThree.setTitle("Demon Slayer");

    Movie movieFour{};
    movieFour.setTitle("ReLIFE");

    movieList.push_back(movieOne);
    movieList.push_back(movieTwo);
    movieList.push_back(movieThree);
    movieList.push_back(movieFour);

    ifstream fileInput{"review.txt"};
    if (!fileInput) {
        cerr << "File not found\n";
        return 1;
    }

    string inputLine{}; // stores each line from the file

    int movieIndex{0};
    while (getline(fileInput, inputLine)) {
        Review review{};
        review.comment = inputLine;

        // Generate a random integer between 10 and 50,
        // then divide by 10.0 to convert it into a decimal
        review.rating = (rand() % (MAX - MIN + 1) + MIN) / 10.0;

        movieList.at(movieIndex).addReview(review);
        movieIndex = (movieIndex + 1) % movieList.size(); // move to the next movie
    }

    for (Movie& movie : movieList)
        movie.printReviews();

    return 0;
}