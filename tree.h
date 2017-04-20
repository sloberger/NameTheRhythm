#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BinaryTree {
public:
    class Node {
    public:
        string question;
        Node * left;
        Node * right;
        Node (string next_question) {
            question = next_question;
            left = NULL;
            right = NULL;
        };
    };
    Node* root;
    BinaryTree(string root_question) {
        root = new Node(root_question);
    };
    ~BinaryTree() {delete root;};
    void insert(string question, Node * root);
    void display(Node * tree, int indent);
    bool isQuestion();
    void traverse(Node * node);
};