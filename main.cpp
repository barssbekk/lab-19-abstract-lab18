#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

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
    // Getter
    string getTitle() { return m_title; }
    Node* getHead() { return m_head; }
    // Setter
    void setTitle(const string& title) { m_title = title; }
    void setHead(Node* head) { m_head = head; }

    void addReview(const Review& review) {
        Node* newNode{new Node};
        newNode->value = review;
        newNode->next = nullptr;

        if (!m_head) {
            m_head = newNode;
        } else {
            Node* current{m_head};
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

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

    void printReviews() {
        Node* current = m_head;
        int count{1};

        cout << "Movie: " << m_title << "\n";

        while (current) {
            cout << "Review #" << count << ": "
                 << current->value.rating << " - "
                 << current->value.comment << endl;

            current = current->next;
            ++count;
        }

        cout << "Average rating: " << calcAvg() << endl;
    }
};

int main() {
    srand(time(0));
    const int MIN{10};
    const int MAX{50};

    vector<Movie> movieList{};
    Movie movieOne{};
    movieOne.setTitle("Attack On Titan");
    movieList.push_back(movieOne);

    ifstream fileInput{"review.txt"};
    if (!fileInput) {
        cerr << "File not found\n";
        return 1;
    }

    string inputLine{}; // To read each line


    while (getline(fileInput, inputLine)) {
        Review review{};
        review.comment = inputLine;
        review.rating = (rand() % (MAX - MIN + 1) + MIN) / 10.0;
        movieList.at(0).addReview(review);
    }

    return 0;
}