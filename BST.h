// Rohan Panuganti
// BST.h
// 5/19/17

/*
  PURPOSE: The purpose of this file is to initialize all the member
  functions and the binary search tree.
*/
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

class BST {

public:

  // constructor 
  BST();

  // desctructor
  ~BST();

  // copy constructor
  BST(const BST &obj);

  // overloaded assignment operator
  BST& operator = (const BST &obj);

  // PRE: constructor initialized
  // POST: bool is returned
  bool empty() const;

  // PRE: constructor initialized
  // POST: bool is returned
  bool search(const int& item) const; 

  // PRE: constructor intialized
  // POST: value is added to the tree
  void insert(const int& item);

  // PRE: the tree must be filled
  // POST: the tree will have one less value
  void remove(const int& item); 

  // PRE: take in one value
  // POST: returns the value's level
  int recursiveLevel(const int& item) const; 

  // PRE: take in one value
  // POST: return the value's level
  int nonRecursiveLevel(const int& item);

  // PRE: take in ostream
  // POST: print the tree by levels
  void levelTraversal(ostream& out) const;

  // PRE: take in ostream
  // POST: print inorder recursively 
  void recursiveInorder(ostream& out) const; 

  // PRE: take in ostream
  // POST: print inorder non recursively 
  void nonRecursiveInorder(ostream& out); 

  // PRE: constructor initialized
  // POST: return the height of the tree
  int height() const;

  // PRE: tree has to be filled
  // POST: print the content of the tree by level
  friend ostream& operator << (ostream& os, const BST& obj);
  
private:
	
  class BinNode {

  public: 

    int data;

    BinNode * left;

    BinNode * right;

    BinNode() : left(0), right(0) {}

    BinNode(int item): data(item), left(0), right(0) {}

    // PRE: data must be filled
    // POST: data is printed
    friend ostream& operator << (ostream& os, const BinNode &obj){
      os << obj.data;
      return os;
    }
    
  }; //end of BinNode

  // PRE: destructor must be called
  // POST: tree is deleted
  void clear(BinNode *&root); // clears the bst

  // PRE: search is called
  // POST: recursively searched
  bool recSearch(BinNode * temp, const int& item) const;

  // PRE: recursive inorder must be called
  // POST: tree is recursively printed
  void recPrint(BinNode * temp, ostream& out) const; 

  // PRE: copy constructor is called
  // POST: copy of tree is created
  BinNode* copy(BinNode * root);

  // PRE: height is called
  // POST: height of the tree is found
  int recHeight(BinNode * root) const;

  // PRE: recursive level functions is called
  // POST: the level is returned as an int
  int recLevel(BinNode * temp, const int& item) const;


  typedef BinNode * BinNodePtr;
  BinNodePtr myRoot;

};

#endif
