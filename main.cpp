#include <iostream>
#include <string>

using namespace std;

struct Review {
    double rating{};
    string comment{};
};

struct Node {
    double value{};
    Node* next{};
};

class Movie {
private:
    string m_title{};
    Node* head{};
public:

};

int main() {
    return 0;
}