#include <iostream>
#include <iomanip>
#include "tree.h"

using namespace std;

void BinaryTree::insert(string question, Node * node) {
    if (question < node->question) {
        if (node -> left != NULL) {
            insert(question, node->left);
        }
        else {
            node->left = new Node(question);
        }
    }
    else if (question > node->question) {
        if (node->right != NULL) {
            insert(question, node->right);
        }
        else {
            node->right = new Node(question);
        }
    }
  }

void BinaryTree::display(Node * node, int indent) {
    if (node != NULL) {

        if (node -> left) display(node->left, indent + 4);
        if (node -> right) display(node->right, indent + 4);
        if (indent) {
            cout << setw(indent) << ' ';
        }
        cout << node->question << endl;
        
    }
}

void BinaryTree::traverse(Node* node) {
    cout << node->question << endl;
    string response;
    cout << "Enter yes/no" << endl;
    cin >> response;
    if (response == "yes") {
        traverse(node->right);
    }
    else {
        traverse(node->left);
    }
    //Need to handle case with leaf node
    
}

bool BinaryTree::isQuestion() {
    if((&right == NULL) && (&left == NULL)) return false;
    return true;
}
