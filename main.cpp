#include <iostream>
#include <string>

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
            Node* current{nullptr};
            while (current->next) {
                current = current->next;
            }
            current->value = review;
        }
    }
};

int main() {
    return 0;
}