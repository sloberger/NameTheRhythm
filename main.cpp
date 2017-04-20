#include <stdio.h>
#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    string next_question;
    BinaryTree tree("5");
    ifstream infile;
    
    infile.open("questions.txt");
    
    while (infile >> next_question) {
        tree.insert(next_question, tree.root);
    }
    
    tree.traverse(tree.root);
}