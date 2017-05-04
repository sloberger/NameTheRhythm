#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BinaryTree {
public:
    class Node {
    public:
        int key;
        string question;
        Node * left;
        Node * right;
        Node (int new_key, string next_question) {
            key = new_key;
            question = next_question;
            left = NULL;
            right = NULL;
        };
    };
    Node* root;
    BinaryTree(string root_question) {
        root = new Node(1, root_question);
    };
    ~BinaryTree() {delete root;};
    void insert(int new_key, string question, Node * root);
    void traverse(Node * node);
};
