////////////////////////////////////////////////////////////////////////////////
// File Name:      tree.hpp
//
// Author:         Sonya Loberger, Rachel Reiter
//
// Description:    A header file for tree.cpp
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
 *@brief A BinaryTree class
 */
class BinaryTree {
public:
    /*
     *@brief A Node class
     */
    class Node {
    public:
        int key;
        string question;
        //children of the node
        Node * left;
        Node * right;
        /**
         * @brief Constructor for the Node class
         */
        Node (int new_key, string next_question) {
            key = new_key;
            question = next_question;
            //initialize children to null
            left = NULL;
            right = NULL;
        };
    };
    Node* root; //the root node of the BinaryTree
    /**
     * @brief Constructor for the BinaryTree class
     */
    BinaryTree(string root_question) {
        root = new Node(1, root_question);
    };
    /**
     * @brief Destructor for the BinaryTree class
     */
    ~BinaryTree() {delete root;};
    /**
     * @brief Insert an element into the BinaryTree
     */
    void insert(int new_key, string question, Node * root);
    /**
     * @brief Traverse the BinaryTree
     */
    void traverse(Node * node);
};
