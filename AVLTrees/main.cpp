#include "AVLtree.h"
#include "Timer.h"

#include <list>
#include <vector>
#include <random>

using namespace std;

int main(int argc, char* argv[]){

  list<float> results_binary; //time for binary

  //for an increasing set of integers
  int tot=10000000;

  int min=0;
  int max=100000;
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(min,max);

  vector<int> values(tot);
  for (int i=0; i<tot; ++i) {
    double number = distribution(generator);
    values.push_back(int(number));
  }

  Timer time;
  time.start();

  //TESTING THE BINARY TREE HERE -----------------------------------------------------
  //TODO.. put the constructor for your binary tree here
  Node *T = NULL;
  BinaryTree bst;

  for(auto i : values){
      //TODO.. call insert on binary tree with value i
      T = bst.insert(i, T);
  }
  time.stop();
  cout << "Time for building (BST) " << time.getElapsedTimeInSec() << endl;

  //select and search 100 randomly generated numbers
  //search numbers in binary tree
  time.start();
  for(int i=tot/2; i < (tot/2) +100; i++){
    int key = values[i];
    //TODO.. call search on binary tree with value key
    Node * temp = bst.find(key, T);
  }
  time.stop();
  cout << "Time for searches (BST) " << time.getElapsedTimeInSec() << endl;


  //select and search 100 randomly generated numbers
  //delete nodes from binary tree
  time.start();
  for(int i=tot/2; i < (tot/2) +100; i++){
    int key = values[i];
    //TODO.. call delete on binary tree with value key
    T = bst.remove(key, T);
  }
  time.stop();
  cout << "Time for delete (BST) " << time.getElapsedTimeInSec() << endl;



  //TESTING THE AVL TREE HERE -----------------------------------------------------
  //TODO.. put the constructor for your AVL tree here
  Node * T1 = NULL;
  AVLTree avl;

  for(auto i : values){
      //TODO.. call insert on AVL tree with value i
      T1 = avl.insertKeepBalanced(i, T1);
  }
  time.stop();
  cout << "Time for building (AVL) " << time.getElapsedTimeInSec() << endl;

  //select and search 100 randomly generated numbers
  //search numbers in AVL tree
  time.start();
  for(int i=tot/2; i < (tot/2) +100; i++){
    int key = values[i];
      //TODO.. call search on AVL tree with value key
      Node * temp = avl.find(key, T1);
  }
  time.stop();
  cout << "Time for searches (AVL) " << time.getElapsedTimeInSec() << endl;


  //select and search 100 randomly generated numbers
  //delete nodes from AVL tree
  time.start();
  for(int i=tot/2; i < (tot/2) +100; i++){
    int key = values[i];
      //TODO.. call delete on AVL tree with value key
      T1 = avl.removeKeepBalanced(key, T1);
  }
  time.stop();
  cout << "Time for delete (AVL) " << time.getElapsedTimeInSec() << endl;


  return 0;
}
