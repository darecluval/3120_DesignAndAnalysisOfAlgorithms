#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

typedef vector<vector<int> > Matrix;

class Graph{

  Matrix graph;

public:
  Graph(int nNodes, int nEdges){
    // you don't have to change anything here. This function will generate a random weighted graph given the
    // desired parameters (number of nodes and number of edges)
    srand (time(NULL));

    graph = Matrix(nNodes, vector<int>(nNodes,0));

    for(int i=0; i<nEdges; i++){
      //random weight
      int weight = rand()%(101);
      int node1, node2;

      do{
        node1 = rand()%(nNodes);
        node2 = rand()%(nNodes);
      }while(node1 == node2 && !connected(node1,node2));

      graph[node1][node2] = graph[node2][node1] = weight;
    }

  }

  int size(){
    //### return the number of nodes in the graph
    return graph.size();
  }

  list<int> getConnectedNodes(int n){
    //### return a list with the nodes connected to node
    list<int> temp;

    for(int i=0; i<graph.size(); i++){

      if (connected(n, i) && i != n){
        temp.push_back(i);
      }

    }

    return temp;
  }

  int getEdgeWeight(int n, int n2){
    //### return the weight assigned to a node
    return graph[n][n2];
  }

  bool connected(int n, int n2){
    //### return true if the two nodes are connected
    if (graph[n][n2] == graph[n2][n] && (graph[n2][n] != 0)){
      return true;
    }
    return false; 
  }

  void print(){
    //### you can implement this for debugging purposes
    for(int i=0; i<graph.size(); i++){
      for(int j=0; j<graph.size(); j++){
        cout << graph[i][j] << " ";
      }
      cout << endl;
    }
  }

};
