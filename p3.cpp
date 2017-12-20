// Rohan Panuganti
// 5/19/17
// p3.cpp
/*
  PURPOSE: The purpose of this program is to test the powers of the
  binary search tree.

  INPUT: This program takes in a file and a couple int values

  PROCESS: The values in the file are parsed using stringstream
  and all the values are inserted into the binary tree. Then each
  function in the BST class is tested.

  OUTPUT: Every functions' results are displayed
 */
#include "BST.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// INPUT: filename and an empty tree
// OUTPUT: the tree is full of values
void readToTree(string fileName, BST &tree);

int main(){
  
  BST tree;
  string fileName = "tree.txt";
  readToTree(fileName, tree);
  cout << endl;

  cout << "12. Checking if tree is filled using level traversal" << endl;
  tree.levelTraversal(cout);
  cout << endl;
  cout << endl;
  
  cout << "1. Testing the copy constructor" << endl;
  BST tree1 = tree;
  tree1.levelTraversal(cout);
  cout << endl;
  cout << endl;

  cout << "2. Testing overloaded assignment operator" << endl;
  BST tree2;
  tree2 = tree;
  tree2.levelTraversal(cout);
  cout << endl;
  cout << endl;

  cout << "3. Checking if the empty function works" << endl; 
  if(!tree2.empty()){
    cout << "tree2 not empty" << endl;
  }

  cout << "and"<< endl;
  BST tree3;
  if(tree3.empty()){
    cout << "tree3 is empty" << endl;
  }
  cout << endl;

  cout << "4. Searching the tree for 22 and 50 "<< endl;
  if(tree.search(22)){
    cout << "22 does exist" << endl;
  }else{
    cout << "22 does not exist" << endl;
  }
  
  if(tree.search(50)){
    cout << "50 does exist" << endl;
  }else{
    cout << "50 does not exist" << endl;
  }

  cout << "5. Inserting 100 and then searching for it" << endl;
  tree.insert(100);
  
  if(tree.search(100)){
    cout << "100 exists" << endl;
  }
  cout << endl;

  cout << "6. Removing 100 and then searching for it" << endl;
  tree.remove(100);
  if(!tree.search(100)){
    cout << "100 does not exist" << endl;
  }
  cout << endl;

  cout << "7. Printing inorder using the overloaded << operator" << endl;
  cout << tree1 << endl;
  cout << endl;

  cout << "8. Testing the recursive inorder " << endl;
  tree1.recursiveInorder(cout);
  cout << endl;

  cout << "9. Testing nonrecursive inorder" << endl;
  tree1.nonRecursiveInorder(cout);
  cout << endl;
  cout << endl;

  cout << "10. Returning the level of 15 using recursion" << endl;
  cout << "Level of 15 is " << tree1.recursiveLevel(15) << endl;
  cout << endl;
  
  cout << "11. Returning the level of 12 without recursion" << endl;
  cout << "Level of 12 is " << tree1.nonRecursiveLevel(12) << endl;
  cout << endl;
  
  cout << "13. Returning the height of the tree" << endl;
  cout << "The height is " << tree1.height() << endl; 
  return 0;
}

void readToTree(string fileName, BST &tree) {
  int n;
  string line;
  ifstream file;
  file.open(fileName.c_str());
  if(file){
    while(getline(file, line)){
      stringstream str(line);
      while (str >> n){
        tree.insert(n);
        if(str.peek() == ','){
          str.ignore();
        } 
      }
    }
  }
  else {
    cout << "File failed to open!";
  }
}
  

  
