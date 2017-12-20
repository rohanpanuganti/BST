// Rohan Panuganti
// BST.cpp
// 5/19/17

#include "BST.h"
#include <stack>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

BST::BST (){
  myRoot = nullptr;
}

BST::BST(const BST &obj){
  myRoot = copy(obj.myRoot);
}

BST& BST::operator = (const BST &obj){
  clear(myRoot);
  myRoot = copy(obj.myRoot);
  
  return *this;
}

ostream& operator << (ostream& os, const BST &obj){
  obj.recursiveInorder(os);
  return os;
}

BST::~BST(){
  clear(myRoot);
}

// checks if empty
bool BST::empty() const{
  if(!myRoot)
    return true;
  return false; 
}

// deletes all nodes in tree
void BST::clear(BinNode *&root){
  if(root){
    clear(root->left);
    clear(root->right);
    delete root;
  }
  root = nullptr;
}

// creates a copy of the tree
BST::BinNode* BST::copy(BinNode * root){
  if(!root){
    return nullptr;
  }

  BinNode * newNode = new BinNode;

  newNode->data = root->data;

  newNode->left = copy(root->left);
  newNode->right = copy(root->right);

  return newNode;
}

// recursive search
bool BST::search(const int& item) const{
  BinNode * temp = myRoot;
  if(!temp) return false;
  return recSearch(temp, item);
}

// recursive search helper function
bool BST::recSearch(BinNode * temp, const int& item) const{
  if(!temp){
    return false;
  }
  
  else if(item < temp->data){
    return recSearch(temp->left, item);
  }

  else if (item > temp->data){
    return recSearch(temp->right, item);
  }
  else {
    return true;
  } 
}

// non recursive insertion
void BST::insert(const int& item) {
  BinNode * node = new BinNode;
  node->data = item;
  node->left = nullptr;
  node->right = nullptr;

  BinNode * temp = myRoot;
  BinNode * parent = nullptr;


  if(!myRoot){
    myRoot = node;
	return;
  } else {
    while(temp){
      if(item < temp->data){
        parent = temp;
        temp = temp->left; 
      }

      else if (item > temp->data){
        parent = temp;
        temp = temp->right;
      } 

      else if(item == temp->data) {
        return;
      }
    }
    if(item < parent->data){
      parent->left = node;
    } else {
      parent->right = node;
    }
  }
}

// recursive level finder
int BST::recursiveLevel(const int& item) const{
  if(!recSearch(myRoot, item)) 
    return -1;
  return recLevel(myRoot, item);
}

// recursive helper level function
int BST::recLevel(BinNode * temp, const int& item) const{
  if(temp->data == item){
    return 0;
  }
  else {
    if(temp->data < item){
      return 1 + recLevel(temp->right, item);
    } else{
      return 1 + recLevel(temp->left, item);
    }
  }
}

// non recursive level finder
int BST::nonRecursiveLevel(const int& item){
  int level = 0;
  BinNode * temp = myRoot;
  
  if(!search(item)) return -1;
  
  while(temp->data != item ){

    if(temp->data < item){
      temp = temp->right;
      level++;
    } else {
      temp = temp->left;
      level++;
    }
  }
  return level;
}

// prints inorder using stack STL
void BST::nonRecursiveInorder(ostream& out) {
  stack <BinNode*> S;
  BinNode * node = myRoot;
  if(!myRoot) return;

  while(!S.empty() || node) {
    while(node){
      S.push(node);
      node = node->left;
    }
    if(!S.empty()) {
      node = S.top();
      S.pop();
      out << *node << " ";
      node = node->right;
    }
  }
}

// print recursively inorder
void BST::recursiveInorder(ostream& out) const{
  if(empty()){
    out << "Tree is empty." << endl;
  } else {
    recPrint(myRoot, out);
  }
}

// recursive helper print inorder function
void BST::recPrint(BinNode * temp, ostream& out) const{
  if(temp) {
    recPrint(temp->left, out);
    out << *temp << " ";
    recPrint(temp->right, out);
  }
}

// return height of tree
int BST::height() const {
  BinNode * root = myRoot;
  return recHeight(root);
}

// helper height function
int BST::recHeight(BinNode * root) const{
  if(!root)
    return -1;
  return 1 + max(recHeight(root->left), recHeight(root->right));
}

// level traversal using queue STL 
void BST::levelTraversal(ostream &out) const{
  queue <BinNode*> Q;
 
  Q.push(myRoot);

  while(!Q.empty()) {
    BinNode * node = Q.front();

    Q.pop();

    out << *node << " ";

    if(node->left){
      Q.push(node->left);
    }
    if(node->right){
      Q.push(node->right);
    }
  }
}

// remove function
void BST::remove(const int& item) {
  if(!search(item)){
    cout << "Item does not exist" << endl;
  } else {

    BinNode * temp = myRoot;
    BinNode * parent = nullptr;
	while(temp){
      if(item < temp->data){
        parent = temp;
        temp = temp->left; 
      }

      else if (item > temp->data){
        parent = temp;
        temp = temp->right;
      } 

      else if(item == temp->data) {
        if(!temp->left && !temp->right){
          delete temp;
        }
        else if(temp->left && !temp->right){
          parent->left = temp->left;
          delete temp;
        }
        else if(temp->right && !temp->left){
          parent->right = temp->right;
          delete temp;
        } else {
          BinNode * end = temp;
          end = end->left;
          while(end->right){
            end = end->right;
          }
          temp->data = end->data;
          end->data = item;
          delete end;
        }
      }
    }
  }
}
