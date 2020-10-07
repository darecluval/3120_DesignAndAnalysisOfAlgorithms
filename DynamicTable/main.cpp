#include <iostream>
#include <fstream>
#include <cmath>

#include "DynamicTable.h"
#include "Timer.h"


using namespace std;

int main() {

    int op =10;
    Timer time;
    ofstream outFile;
    outFile.open("results.txt");
    for(op=1; op<1000; op++){

        DynamicTable table = DynamicTable();

        time.start();
        for(int i=0; i<op; i++){
            table.insert(10);
        }
        time.stop();
       outFile << time.getElapsedTime() << endl;
    }

    outFile.close();

    return 0;
}
