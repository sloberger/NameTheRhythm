#include <stdio.h>
#include <iostream>
#include <sstream>
#include "tree.h"

using namespace std;

int main() {
    string next_question;
    BinaryTree tree("1 Is there an R-R interval?");
    ifstream infile;
    
    infile.open("questions.txt");
    
    while (getline(infile, next_question)) {
        int key = 0;
        string skey;
        if( stringstream(next_question) >> skey) {
            key = stoi(skey);
            next_question.erase(next_question.begin(), next_question.begin() + skey.size());
        }
        tree.insert(key, next_question, tree.root);
    }
    
    tree.traverse(tree.root);
}
