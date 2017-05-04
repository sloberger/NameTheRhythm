#include <iostream>
#include <iomanip>
#include "tree.h"

using namespace std;

void BinaryTree::insert(int new_key, string question, Node * node) {
    if (new_key < node->key) {
        if (node -> left != NULL) {
            insert(new_key, question, node->left);
        }
        else {
            node->left = new Node(new_key, question);
        }
    }
    if (new_key > node->key) {
        if (node->right != NULL) {
            insert(new_key, question, node->right);
        }
        else {
            node->right = new Node(new_key, question);
        }
    }
}

void BinaryTree::traverse(Node* node) {
    string response;
    if (node->right != NULL || node->left != NULL) {
        node->question.erase(node->question.begin(), node->question.begin() + 1);
       cout << node-> question << " (yes/no)" << endl;
    }
    else {
        cout << "The Rhythm is:" << node->question << endl;
        return;
    }
    
    cin >> response;
    if (response == "yes") {
        if (node->right != NULL) {
            traverse(node->right);
        }
        else {
            return;
        }
    }
    else {
        if (node->left != NULL) {
            traverse(node->left);
        }
        else {
            return;
        }
    }
}