# Dynamic Tables

In this assignment, we will verify if the accounting method does a good job in estimating the complexity of a sequence of insertion in a dynamic table.


### Step 1 - Setup

The `main.cpp` file provides the code needed to test your implementation of the Dynamic Table. Nothing to be changed here so far.

`Time.*` are also two external libraries that will help you estimating the time required for performing certain operations. Nothing to be changed here.

`DynamicTable.*` contains the DynamicTable class that you have to implement. Before starting with that, let's try to compile the project to check that everything is ready.

If you are familiar with `cmake`, I am already providing a cmake file for compiling the project. In this case just run the following commands:

```bash
mkdir build
cd build
cmake ..
make
```

you should obtain the executable named `dynamicTable` in the `build` directory.
If you do not want to use cmake you can compile the program from the main folder with the following command.

```bash
g++ main.cpp DynamicTable.cpp Timer.cpp -o dynamicTable
```

### Step 2 - Implementing the Dynamic Table

As we have seen in class, a dynamic table is an array that automatically resize itself when it gets full. This can be implemented by combining two simple functions, `insert` and `resize`.

* Header file - Start from `DynamicTable.h`, and implement the constructor and destructor of the table. This are the functions called when you create a new Dynamic Table or when you don't need it anymore.

* Implementation - Now implement the two functions insert and resize in `DynamicTable.cpp`

### Step 3 - Testing and Evaluation

According to `main.cpp` we are inserting an integer (the value 10) into the table `op` times. Check that everything is correct by running the program with increasing values of `op`. `Timer` is tracking the time needed to perform the insertions into the table. You can add the line

```c++
cout << time.getElapsedTime() << endl;
```
to print out the time occurred. Once you are confident the implementation is correct uncomment the remaining commented lines

What is the code supposed to do now?
The code prints out the time it takes to insert 10 for the amount of operations in the for loop.



We want to test if it is true that by increasing the size of our input the increase in complexity is not quadratical (`O(n^2)`) but linear (`O(n)`). Once the program has been executed you should get a file in output `results.txt`. Run the following command in python to get a graphical representation of the timings (be sure that plot_time.py and results.txt are in the same folder when you run it)

```bash
python plot_time.py
```

How is the graph obtained related to amortized analysis?
The graph shows that when the size of the input increases then the algorithm, then the complexity trends towards linear opposed to quadratically. 
