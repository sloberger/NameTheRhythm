////////////////////////////////////////////////////////////////////////////////
// File Name:      tree.cpp
//
// Author:         Sonya Loberger, Rachel Reiter
// CS email:       loberger@cs.wisc.edu
//
// Description:    A program that creates a BinaryTree, and traverses it to help
//                 the user identify specific cardiac rhythms.
//
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "tree.h"

using namespace std;

void BinaryTree::insert(int new_key, string question, Node * node) {
    if (new_key < node->key) {
        if (node -> left != NULL) {
            insert(new_key, question, node->left); //recursively insert on the left
        }
        else {
            node->left = new Node(new_key, question); //initialize a new Node
        }
    }
    else if (new_key > node->key) {
        if (node->right != NULL) {
            insert(new_key, question, node->right); //recursively insert on the right
        }
        else {
            node->right = new Node(new_key, question); //initialize a new Node
        }
    }
}

void BinaryTree::traverse(Node* node) {
    string response;
    //prints question and asks user for response if it is not a leaf node
    if (node->right != NULL || node->left != NULL) {
        cout << node-> question << " (yes/no)" << endl;
    }
    else {
        //If current node is a leaf, identify the rhythm
        cout << "The Rhythm is: " << node->question << endl;
        return;
    }
    
    cin >> response; //user provided response
    //traverse to the right if user inputs yes
    if (response == "yes" || response == "y") {
        if (node->right != NULL) {
            traverse(node->right);
        }
        else {
            return;
        }
    }
    //traverse to the left if user inputs no
    else if (response == "no" || response == "n"){
        if (node->left != NULL) {
            traverse(node->left);
        }
        else {
            return;
        }
    }
}