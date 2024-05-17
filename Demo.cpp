//324933993
//anthoniosdb@gmail.com
#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
using namespace ariel;

int main()
{
    Graph g1;
    vector<vector<int>> adjmat1 = {
        {0, 1, 2, 0, 0},
        {1, 0, 6, 0, 0},
        {2, 6, 0, 9, 0},
        {0, 0, 9, 0, 0},
        {0, 0, 0, 0, 0}};
    g1.loadGraph(adjmat1);

    g1--;

    

    return 0;
}