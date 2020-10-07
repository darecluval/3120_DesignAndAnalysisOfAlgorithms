#include "matrixChain.h"

using namespace std;

int main(void) {

    MatrixChain chain = MatrixChain(100);
    chain.printDimensions();
    Matrix K = chain.dynamicChain();    

    return 0;
}