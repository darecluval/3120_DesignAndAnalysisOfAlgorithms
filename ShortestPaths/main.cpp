#include "Graph.h"
#include "Timer.h"
#include <queue>
#include <iomanip>

using namespace std;


int MAX = numeric_limits<int>::max();
int REP = 1000000;


//####implement the Dijkstra’s Algorithm here
vector<int> computeShortestPath(Graph g, int node){

  //for each vertex u =/= v of G do D[u] ← +∞
  vector<int> D(g.size(), REP);

  //D[v] ← 0
  D[node] = 0;

  //Let a priority queue, Q, contain all the vertices of G using the D labels as keys.
  priority_queue<pair<int,int>, vector<pair<int,int> >,  greater<pair<int,int> > > Q;

  Q.push(make_pair(0, node));

  // pull a new vertex u into the cloud
  int u;

  //while Q is not empty do
  while (!Q.empty()){

    //u ← Q.removeMin()
    u = Q.top().second; 
    Q.pop(); 

    list<int> neighbors = g.getConnectedNodes(u);
    list<int>::iterator i;

    //for each vertex z adjacent to u such that z is in Q do
    for (i = neighbors.begin(); i != neighbors.end(); i++){//(int z : neighbors){

      int z = *i;
      int w = g.getEdgeWeight(u, z);

      // perform the relaxation procedure on edge (u, z) if D[u] + w((u, z)) < D[z] then
      if (D[z] > D[u] + w) { 

        //D[z] ← D[u] + w((u, z)) 
        D[z] = D[u] + w; 
        //Change the key for vertex z in Q to D[z]
        Q.push(make_pair(D[z], z)); 

      } 
    }
  }

  return D;

};

//####compute all possible shortest paths by calling the Dijkstra's Algorithm on each pair of nodes
vector<vector<int> > computeAllPairsShortestPath(Graph g){

  vector<vector<int> > SP;
  for(int i=0; i<g.size(); i++){
    SP.push_back(computeShortestPath(g, i));
  }

  return SP;

};

Matrix computeAllPairsShortestPathDynamicProgramming(Graph g){
  //BONUS
  //####compute all possible shortest paths by implementing the dynamic programming approach

  int n = g.size();

  // Create a vector of matrices with size [n][n][n]
  Matrix temp = Matrix(n, vector<int>(n, 0));
  vector<Matrix> D;
  for (int m=0; m<n; m++){
    D.push_back(temp);
  }

  // for i ← 1 to n do
  for (int i=0; i < n; i++) {

    // for j ← 1 to n do
    for (int j=0; j < n; j++) {

      // cout << i << " " << j << endl;

      // if i = j then D0[i,i] ← 0
      if (i == j) {

        D[0][i][i] = 0;
        
      } 

      // if (vi,vj) is an edge in G then
      else if (g.connected(i,j)) {

        // D0[i,j] ← w((vi,vj)) 
        D[0][i][j] = g.getEdgeWeight(i,j);

      } 

      // else D0[i, j] ← +∞ 
      else {

        D[0][i][j] = REP;

      }
    }
  }

  // for k ← 1 to n do
  for (int k=1; k < n; k++) {

    // for i ← 1 to n do
    for (int i=0; i < n; i++) {

      // for j ← 1 to n do
      for (int j=0; j < n; j++) {
        
        int t = std::min(D[k-1][i][j], D[k-1][i][k] + D[k-1][k][j]);
        D[k][i][j] = t;

      }
    }
  }

  // return matrix Dn
  return D[n-1];

};

bool compareResults(Graph g, Matrix a, Matrix b){

  for(int i=0; i<g.size(); i++){
    for(int j=0; j<g.size(); j++){
      if(a[i][j] != b[i][j]){
        return false;
      }
    }
  }

  return true;
}


int main(){

  //create graph as a random matrix
  Graph g(1000,40000);
  cout << "Graph generated " << endl;

  //compute shortest path
  Timer time;
  time.start();
  Matrix a = computeAllPairsShortestPath(g);
  time.stop();
  cout << "Time with Dijkstra's algorithm: " << time.getElapsedTimeInSec() << endl;

  // compute all possible shortest paths
  time.start();
  Matrix b = computeAllPairsShortestPathDynamicProgramming(g);
  time.stop();
  cout << "Time with Dynamic programming: " << time.getElapsedTimeInSec() << endl;

  //compute by dynamic programming approach
  if(compareResults(g,a,b)){
    cout << "They are the same" << endl;
  }
  else{
    cout << "Different" << endl;
  }

};
