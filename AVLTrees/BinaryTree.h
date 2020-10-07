#ifndef BINARYTREE_H_DEF
#define BINARYTREE_H_DEF

#include <stdlib.h>
#include <iostream>

using namespace std;

class Node{

  //Each node should have
  //- pointer to the parent node
  //- pointer to left child
  //- pointer to right child
  //- int for storing the key value

  Node* parent;
  Node* left;
  Node* right;
  int key;
  int height;


public:

  //constructor
  //remember to always inizialize pointers to NULL
  //getter and setter for other nodes and value
  Node(int k){
    parent = left = right = NULL;
    key = k;
    height = 1;
  }

  //Setters
  void setParent(Node * p){
    this->parent = p;
  }

  void setLeft(Node * l){
    this->left = l;
  }

  void setRight(Node * r){
    this->right = r;
  }

  void setKey(int k){
    this->key = k;
  }

  void setHeight(int h){
    this->height = h;
  }

  //Getters
  Node * getParent(){
    return this->parent;
  }

  Node * getLeft(){
    return this->left;
  }

  Node * getRight(){
    return this->right;
  }

  int getKey(){
    return this->key;
  }

  int getHeight(){
    return this->height;
  }

};

class BinaryTree{

protected:
  //A tree should store its root only.
  Node* root;

private:

public:
  //functions required

  //- constructor
  BinaryTree(){
    root = NULL;
  }

  //- getter setter root
  void setRoot(Node * r){
    this->root = r;
  }

  //Getters
  Node * getRoot(){
    return this->root;
  }

  //- a function for printing the inorder visit of the tree
  void printInOrder(Node * T){
    if (T != NULL){
      printInOrder(T->getLeft());
      cout << T->getKey() << " " << endl;
      printInOrder(T->getRight());
    }
  }

  //- a function for searching a value in the tree.
  Node * find(int k, Node *T){
    if (!T) { return NULL; }
    if (k == T->getKey()) { return T; }
    if (k < T->getKey()) { return find(k, T->getLeft()); }
    else { return find(k, T->getRight()); }
  }

  //- a function for inserting a new value in the tree
  Node * insert(int k, Node * T) {
    if (!T || T->getKey() == k) {
      Node * root = new Node(k);
      return root;
      cout << "here" << endl;
    }

    T->setHeight((T->getHeight())+1);

    //size
    if (k < T->getKey()) {
      T->setLeft(insert(k, T->getLeft()));
    } else {
      T->setRight(insert(k, T->getRight()));
    }

    return T;
  }

  //Get minimum key of a tree
  Node * getMinKey(Node * T){
    if (!T) { return NULL; }
    else if (!T->getLeft()) { return T; }
    else { return getMinKey(T->getLeft()); }
  }

  //Get maximum key in a tree
  Node * getMaxKey(Node * T) {
    if (!T) { return NULL; }
    else if (!T->getRight()) { return T; }
    else { return getMaxKey(T->getRight()); }
  }


  //- a function for deleting a value from the tree
  Node * remove(int k, Node * T){
    
    //Case 1: Not found
    if (!T) { return NULL; }

    //Case 2: Searching for element
    else if (k < T->getKey()) {
      T->setLeft(remove(k, T->getLeft()));
    } else if (k > T->getKey()) {
      T->setRight(remove(k, T->getRight()));
    }

    //Case 3: Element found
    //    w/ both chilldren
    else if (T->getLeft() && T->getRight()) {
      Node * tempT = getMinKey(T->getRight());
      T->setKey(tempT->getKey());
      T->setRight(remove(T->getKey(), T->getRight()));
    }

    //    w/ one or zero chilldren
    else {
      Node * tempT = T;
      if (!T->getLeft()) { T = T->getRight(); }
      else if (!T->getRight()) { T = T->getLeft(); }
      delete tempT;
    }


    return T;

  }

  int height(Node * T){
    if (T == NULL){
      return 0;
    }
    return T->getHeight();
  }

};

#endif
