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
};

int main() {
    return 0;
}