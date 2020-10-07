# Binary trees and Splay trees

In this assignment, we will implement two distinct data structures. One is a simple Binary Search Tree and the second one is a AVL tree.

All the information you need regarding these two data structures can be found in your textbook (Algorithm Analysis and Design, Chapter 4).



### Step 1 - Setup

The `main.cpp` file provided with the assignment will be used at the end for testing the performances of the data structures. For the initial debugging phase I suggest you create a simple main file with the minimal instructions you will need for verifying that the implemented structures are working correctly.

###### Suggestion
keep your code hierarchy simple. Ideally, you should always be able to compile everything with something like `g++ main.cpp Timer.cpp -std=c++11 -o main`

### Step 2 - Implementing the Binary tree

Use the draft provided in `BinaryTree.h` for implementing a binary search tree. The comments provided in the file should guide you through all the required variables/functions you will need to define.

###### Suggestion
The inorder visit can be a powerful debugging tool. Remember that in a Binary search tree as well as in the AVL tree an inorder visit should always return the keys stored in the tree in ascending order. If this is not happening, it means that something is wrong with your insert/remove/rotate implementation.
M
###### Suggestion
Every time you perform a search and an insert in a AVL tree you shoulld return the last (non null) node touched. You can implement this in the Binary search tree as well. This way we will reuse this function for implementing the `insert`, `search` and `delete` in the AVL tree.  



### Step 3 - Implementing the AVL tree

Use the draft provided in `AVLTree.h` for implementing a AVL tree. The comments provided in the file should guide you through all the required variables/functions you will need to define.

###### Suggestion
There are two types of rotations in the AVL tree (single and double). Each of them can be performed on the left or on the right. I strongly encourage you to define four distinct functions for implementing each combination (single left, single right, double left, double right). These will be easier to debug.

###### Suggestion
If you have implemented the `insert` `delete` and `search` functions in the Binary tree as suggested, you should be able to reuse your code. Ideally, your functions here should be something like

```c++
  bool insert(int key){
    Node* last = BinaryTree::insert(key, getRoot());
    balance(last)
  }
```

```c++
  bool delete(int key){
    Node* last = BinaryTree::delete(key, getRoot());
    balance(last)
  }
```

```c++
  bool search(int key){
    Node* last = BinaryTree::search(key, getRoot());
    balance(last)
  }
```

### Step 4 - Evaluation and Submission

Assuming that you have implemented everything and debugged your code now it is time to evaluate these two data structures. You can go back to the `main.cpp` file provided with the assignment and fill the missing lines identified by `TODO` (these should be only simple calls to your data structure functions).


###### Experiments

You should be able to compile everything with `g++ main.cpp Timer.cpp -std=c++11 -o main`

Play with the code and compare the timings you get when changing the parameters `tot`, `min`, `max`. What do you notice? Describe the parameters you used, the results you got and how they relate to what studied in class.

When I run the program with the parameter "tot" my bst and avl trees take about 4.5 seconds to insert nodes into their trees. When I run it with min, it takes about 3.7 seconds. And with max it runs in about 3.9 seconds.

The reason for this is because less numbers are used to build the values int array so the algorithm has less values to insert/search/remove. 
