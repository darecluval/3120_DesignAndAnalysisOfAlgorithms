# Graph problems, shortest paths

In this assignment, we will implement two distinct algorithms for computing the shortest paths between all possible pairs of nodes in a graph

All the information you need regarding these two data structures can be found in your textbook (Algorithm Analysis and Design, Chapter 14).

### Step 1 - Implementing the graph

We will implement the graph by simply using an adjacency matrix. In the file Graph.h you are already provided with a structure for the class Graph and the actual implementation of the Matrix (a simple vector of vectors).

The constructor of the Graph takes in input two integers indicating the number of nodes and number of arcs.
The construct randomly generates a representation for the weighted graph.

You have to implement the other functions listed in Graph.h

Keep your code simple.
There is no need for additional files so you can implement everything inline. You should be able to compile your code using the following `g++ Time.cpp main.cpp -o main`.
You are not allowed to reuse code from other classes. Integrate your code into the current structure.

### Step 2 - Implementing the Dijkstra’s Algorithm

The algorithmic description of Dijkstra’s Algorithm can be found in your textbook. A few tips:

- Use `MAX` to represent the maximum distance between two nodes instead of infinite (I have already defined MAX for you).
- You can use the priority queue provided by the standard. Use the following code for defining the queue.

  `priority_queue<pair<int,int>, vector<pair<int,int> >,  greater<pair<int,int> >> q;`

  With this, you are declaring a priority queue of pairs of integers. Practically, each element in the queue will be a pair of integers (`pair<int,int>,`) and you are creating a vector of pairs (`vector<pair<int,int> >,`). Moreover, the elements will be sorted in ascending order (`greater<pair<int,int> >`).

- By default, if you provide a pair to the priority queue, the first element of the pair will be used for ordering the elements. If you look at Dijkstra’s Algorithm, we want the elements in the queue to be sorted according to their distance from the source. This means that, for each pair, the first element has to encode the distance of the node from the source while the second element has to store the index of such node in the graph.


### Step 3 - Implementing the computeAllPairsShortestPath function

Once the Dijkstra’s Algorithm is implemented this step will be easy. You just have to call the Dijkstra’s Algorithm using the source each possible node in your graph. Save your results in a Matrix such that, for each pair of indices (i,j), Matrix(i,j) will store the length of the shortest between those two nodes.


### Step 4 BONUS - Implementing the Dynamic Programming Algorithm

Implement the dynamic programming solution for computing all pairs of shortest pairs (Chapter 14.5.1).

Once the algorithms are implemented, evaluate their performances. Test your implementation with different graphs.

*** NOTE: MAX was replaced with 1000000 since if I set it to INT_MAX, then there was an overload when it goes to add it to another number - thus having an overload error and bit shifting to a negative number - ruining the min operation

- use a simple graph with 10 nodes and 20 arcs
Graph generated 
Time with Dijkstra's algorithm: 0.000476
Time with Dynamic programming: 0.000226
They are the same

The times are so low that the times are miniscule, but the Dijkstra's is longer since there are more arcs than nodes therefore it creates more potential routes and the PQ will be longer. The Dynamic Programming doesn't change as much since the only thing it won't do is go farther into the first double for loop since it's more likely two nodes will be connected, and it won't have to go into the final else statment and set it to MAX.

- increment the number of nodes to be lower than the number of arcs (1000, 500)
Graph generated 
Time with Dijkstra's algorithm: 9.80868
Time with Dynamic programming: 51.3751
They are the same

Dijkstra's takes shorter since the PQ stays shorter with the lack of neighbors for each node. The Dynamic Programming takes longer since it's less likely for two nodes to be connected, it has to go farther into the first double for loop to set the max value to that pair. 

- increment the number of arcs (1000, 40000)
Graph generated 
Time with Dijkstra's algorithm: 232.514
Time with Dynamic programming: 53.3811
They are the same

Dijkstra's takes longer since the average node has more neighbors causing the PQ have more potential routes. There increase in time comes from having to deal with the larger PQ. Dynamic Programming takes shorter since two nodes are more likely to be connected and so it doesn't have to go as deep into the first double for loop unlike when the number of nodes is more than the number of edges. 

Open this README file with a normal text editor and report the timings obtained discussing the reason why you obtained each result.
