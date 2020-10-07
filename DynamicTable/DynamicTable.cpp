#include "DynamicTable.h"

void DynamicTable::insert(int value) {
    //add a new element in the table
    if (size == last) {
      resize();
    }
    table[last++] = value;
}

void DynamicTable::resize() {
    //resize the table when necessary
    int * tempTable = new int[size*2];

    //Copy over values and set other values to 0
    for (int i = 0; i < size; i++) {
      tempTable[i] = table[i];
    }

    //Switch reference to pointer to new table
    delete [] table;
    table = tempTable;
    size = size * 2;
}
