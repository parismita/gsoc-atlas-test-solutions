# gsoc-atlas-test-solutions
Faster Matrix Algebra For ATLAS

Here is the link to the Gsoc Proposal: [link](https://github.com/parismita/gsoc-atlas-test-solutions/blob/master/gsoc-atlas-2018.pdf)

This is a solution to evaluation test [link](https://github.com/StewMH/GSoC2018/blob/master/evaluation_test.pdf). To run the code: `./run.sh`

To run the test.cpp file:

`g++ -I ~/eigen/ -std=c++11 test.cpp SymMAt.a`

`./a.out
`

To run the eg.cpp file:

`g++ -I ~/eigen/ -std=c++11 eg.cpp SymMAt.a`

`./a.out > op.txt`

The SymMat.h is the header file for class SymMat. 
The file test.cpp is the unittest written to check the code correctness. 
The file eg.cpp is the example use case for SymMat class
