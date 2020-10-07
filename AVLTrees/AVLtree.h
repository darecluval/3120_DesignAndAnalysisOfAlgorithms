#ifndef AVLTREE_H_DEF
#define AVLTREE_H_DEF

#include "BinaryTree.h"

//class implementing the Splay tree
class AVLTree : public BinaryTree{

  //by extending the Binary you have everything you need expect the rank value

public:

  //TODO:

  //a new function for inserting a node into the tree
    //you can start by callling the insert function from the binary tree
    //additionally you have to perform rotations if necessary
  Node * insertKeepBalanced(int k, Node * T){

    T = BinaryTree::insert(k, T);
    return rebalanceTree(T, k);

  }

  Node * findAVL(int k, Node *T){
    return BinaryTree::find(k, T);
  }

  //Get the height differnce between the left and right child nodes
  int getHeightDiff(Node * T){
    if (!T){
      return 0;
    }
    return T->getLeft()->getHeight() - T->getRight()->getHeight(); //** may need height()
  }

  //Update heights following rebalanceTree
  int updateHeights(Node * T){

    return max(T->getLeft()->getHeight(), T->getRight()->getHeight()) + 1; //** may need height()
  }

  //Rebalance the tree
  Node * rebalanceTree(Node * T, int key){

    if (T->getLeft() && T->getRight()){
      int childDiff = getHeightDiff(T);


      //Case 1: Double left rotation
      if (childDiff > 1 && getHeightDiff(T->getLeft()) >= 0){
        return rightRotation(T);
      }

      //Case 2: Double right rotation
      if (childDiff < -1 && getHeightDiff(T->getRight()) <= 0){
        return leftRotation(T);
      }

      //Case 3: Right Left rotation
      if (childDiff < -1 && getHeightDiff(T->getRight()) > 0) {
        T->setRight(rightRotation(T->getRight()));
        return leftRotation(T);
      }

      //Case 4: Left Right rotation
      if (childDiff > 1 && getHeightDiff(T->getLeft()) < 0) {
        T->setLeft(leftRotation(T->getLeft()));
        return rightRotation(T);
      }
    }

    //catch all
    return T;

  }

  //a new function for deleting a node into the tree
    //you can start by callling the delete function from the binary tree
    //additionally you have to perform rotations if necessary
  Node * removeKeepBalanced(int k, Node * T) {

    T = BinaryTree::remove(k, T);

    //Then rebalance
    T->setHeight(updateHeights(T) + 1);
    return rebalanceTree(T, k);

  }

  //two new functions for performring left rotations
  //two new functions for performring right rotations
  Node * rightRotation(Node * T){
    Node * newT = T->getLeft();
    T->setLeft(newT->getRight());
    newT->setRight(T);
    T->setHeight(updateHeights(T) + 1);
    newT->setHeight(updateHeights(T) + 1);
    return newT;
  }

  Node * leftRotation(Node * T){
    Node * newT = T->getRight();
    T->setRight(newT->getLeft());
    newT->setLeft(T);
    T->setHeight(updateHeights(T) + 1);
    newT->setHeight(updateHeights(T) + 1);
    return newT;
  }

  Node * doubleRightRotation(Node * T){
    T->setLeft(leftRotation(T->getLeft()));
    return rightRotation(T);
  }

  Node * doubleLeftRotation(Node * T){
    T->setRight(rightRotation(T->getRight()));
    return leftRotation(T);
  }

};

#endif
