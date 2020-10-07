#include "matrixChain.h"

#include <random>
#include <vector>
#include <iostream>

using namespace std;

MatrixChain::MatrixChain(int num){
  dimensions = vector<int>(num+1,0);
  for(int i=0;i<num+1;i++){
    int dim = rand()%SIZE+1;
    dimensions[i]=dim;
  }

  for(int i=0;i<num;i++){
    generate_matrix(dimensions[i],dimensions[i+1]);
  }
}

void MatrixChain::generate_matrix(int rows, int cols){
  srand(time(0));

  Matrix matrix(rows, vector<int>(cols,0));
  for (int j=0;j<rows;j++){//row
    for (int k=0;k<cols;k++){//
          matrix[j][k] = rand()%NUM+1;
      }
  }
  chain.push_back(matrix);
}

//implement here the simple multiplication between two matrices
Matrix MatrixChain::multiply(Matrix a, Matrix b){
  Matrix ret;
    for (int i = 0; i < a.size(); ){
        for (int j = 0; j < b.size(); ){
            for (int k = 0; k < a.size();k++)
                ret[i][j] += a[i][k] * b[k][j];
        }
    }
    return ret;
}

//implement here the optimal approach using the dynamic programming algorithm
Matrix MatrixChain::dynamicChain(){

  int n = chain.size(), min, temp;
  Matrix N(n, vector<int>(n,0));
  Matrix K(n, vector<int>(n,0));

  // for i ← 0 to n − 1 do Ni,i ← 0
  for (int i = 0; i < n; i++){
    N[i][i] = 0;
  }

  // for b ← 1 to n − 1 do
  for (int b = 1; b < n; b++){

    // for i ← 0 to n − b − 1 do j←i+b and Ni,j ← +∞
    for (int i = 0; i < (n-b); i++) {
      int j = i+b;
      N[i][j] = INT_MAX;

      // for k ← i to j − 1 do Ni,j ← min{Ni,j, Ni,k + Nk+1,j + didk+1dj+1}.
      for (int k = i; k < j; k++) {

        //Keep best
        temp = std::min(N[i][j], N[i][k] + N[k+1][j] + dimensions[i] * dimensions[k+1] * dimensions[j+1]);
        if (temp < N[i][j]){
          N[i][j] = temp;
          K[i][j] = k;
        }
      }

      // Keep end of the loop
      min = N[i][j];
    }
  }

  // Print most optimal solution 
  cout << "Optimal Solution: " << min << " multiplications." << endl;
  return K;
}
