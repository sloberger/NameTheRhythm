#include <stdio.h>
#include <iostream>
#include <sstream>
#include "tree.h"

using namespace std;

int main() {
    
    string next_question;
    ifstream infile;
    BinaryTree tree("1 Is there an R-R interval?"); //initial tree
    
    infile.open("questions.txt");
    
    //parse input into key and question,
    while (getline(infile, next_question)) {
        int key = 0;
        string skey;
        if( stringstream(next_question) >> skey) {
            key = stoi(skey);
            //remove the number from the input string
            next_question.erase(next_question.begin(), next_question.begin() + skey.size() + 1);
        }
        tree.insert(key, next_question, tree.root); //insert entry
    }
    //traverse tree for user 
    tree.traverse(tree.root);
}
