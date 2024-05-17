//324933993
//anthoniosdb@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace ariel;

TEST_CASE("Test isConnected undirected unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph3 = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 1, 1, 1, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0, 1, 1, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected undircted Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 2, 0},
        {2, 0, 3},
        {0, 3, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph1 = {
        {0, 1, 2, 0, 0},
        {1, 0, 6, 0, 0},
        {2, 6, 0, 9, 0},
        {0, 0, 9, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph2 = {
        {0, 3, 6, 0, 0, -5},
        {3, 0, 3, 7, 0, 0},
        {6, 3, 0, 0, 8, 0},
        {0, 7, 0, 0, -3, -2},
        {0, 0, 8, -3, 0, 1},
        {-5, 0, 0, -2, 1, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph3 = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 3, 7, 0, 0},
        {0, 3, 0, 0, 8, 0},
        {0, 7, 0, 0, -3, -2},
        {0, 0, 8, -3, 0, 1},
        {0, 0, 0, -2, 1, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph4 = {
        {0, 2, 4, 0, 0, 0, 0, 1},
        {2, 0, 5, 3, 0, 0, 0, 0},
        {4, 5, 0, 7, 0, 0, 0, 0},
        {0, 3, 7, 0, -5, 0, 0, 0},
        {0, 0, 0, -5, 0, 6, 7, 0},
        {0, 0, 0, 0, 6, 0, 4, 2},
        {0, 0, 0, 0, 7, 4, 0, 5},
        {1, 0, 0, 0, 0, 2, 5, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test isConnected dircted unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph1 = {
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        // 0  1  2  3  4  5  6  7  8
        {0, 0, 1, 0, 0, 1, 0, 0, 0},  // 0
        {0, 0, 0, 0, 0, 0, 1, 0, 0},  // 1
        {0, 0, 0, 0, 0, 0, 1, 0, 0},  // 2
        {0, 0, 0, 0, 1, 0, 0, 0, 0},  // 3
        {0, 0, 0, 0, 0, 1, 0, 0, 0},  // 4
        {0, 0, 0, 1, 0, 0, 0, 1, 0},  // 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 6
        {0, 0, 1, 0, 0, 0, 0, 0, 1},  // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 8
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test isConnected dircted Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph1 = {
        {0, 0, 2, 9, 0, 0},
        {6, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 4},
        {0, -6, 0, 3, 0, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 0, 8, 1, 0, 0},
        {2, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 9, 0},
        {0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        // 0  1  2  3  4  5  6  7  8
        {0, 0, -1, 0, 0, 6, 0, 0, 0}, // 0
        {0, 0, 0, 0, 0, 0, 3, 0, 0},  // 1
        {0, 0, 0, 0, 0, 0, 9, 0, 0},  // 2
        {0, 0, 0, 0, 12, 0, 0, 0, 0}, // 3
        {0, 0, 0, 0, 0, 5, 0, 0, 0},  // 4
        {0, 0, 0, 6, 0, 0, 0, 7, 0},  // 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 6
        {0, 0, 10, 0, 0, 0, 0, 0, 3}, // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 8
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath undirected unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 1, 4) == "-1");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 1, 5) == "1->3->5");
}

TEST_CASE("Test shortestPath undirected Weighted")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {0, 0, 4},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(Algorithms::shortestPath(g, 1, 0) == "-1");
    CHECK(Algorithms::shortestPath(g, 2, 1) == "-1");

    vector<vector<int>> graph2 = {
        {0, 2, 7, 0, 0},
        {2, 0, 3, 0, 0},
        {7, 3, 0, 2, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");
    CHECK(Algorithms::shortestPath(g, 3, 0) == "3->2->1->0");

    vector<vector<int>> graph4 = {
        {0, 1, 5, 0, 0, 1},
        {1, 0, 6, 1, 0, 0},
        {5, 6, 0, 0, 4, 0},
        {0, 1, 0, 0, 3, 2},
        {0, 0, 4, 3, 0, 1},
        {1, 0, 0, 2, 1, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::shortestPath(g, 1, 5) == "1->0->5");
}

TEST_CASE("Test shortestPath directed unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(Algorithms::shortestPath(g, 2, 0) == "-1");

    vector<vector<int>> graph1 = {
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::shortestPath(g, 4, 0) == "4->3->2->0");

    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 2, 5) == "-1");

    vector<vector<int>> graph3 = {
        // 0  1  2  3  4  5  6  7
        {0, 0, 1, 0, 0, 1, 0, 0},  // 0
        {0, 0, 0, 0, 0, 0, 1, 0},  // 1
        {0, 0, 0, 0, 0, 0, 1, 0},  // 2
        {0, 0, 0, 0, 1, 0, 0, 0},  // 3
        {0, 0, 0, 0, 0, 1, 0, 0},  // 4
        {0, 0, 0, 1, 0, 0, 0, 1},  // 5
        {0, 0, 0, 0, 0, 0, 0, 0},  // 6
        {0, 0, 1, 0, 0, 0, 0, 0}}; // 7
    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 1, 0) == "-1");
    CHECK(Algorithms::shortestPath(g, 3, 6) == "3->4->5->7->2->6");
}

TEST_CASE("Test shortestPath directed Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 2, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    CHECK(Algorithms::shortestPath(g, 2, 0) == "-1");

    vector<vector<int>> graph1 = {
        {0, 0, 0, 0, 0},
        {6, 0, 0, 0, 0},
        {3, 1, 0, 0, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, -2, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::shortestPath(g, 4, 0) == "4->3->2->0");

    vector<vector<int>> graph3 = {
        {0, -1, 0, 0, 0, 0},
        {0, 0, -4, 0, 0, 0},
        {12, 11, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {-9, 0, 0, 6, 0, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 2, 5) == "-1");

    vector<vector<int>> graph4 = {
        // 0  1  2  3  4  5  6  7
        {0, 0, 2, 0, 0, 1, 0, 0},    // 0
        {0, 0, 0, 0, 0, 0, 1, 0},    // 1
        {0, 0, 0, 0, 0, 0, 1, 0},    // 2
        {0, 0, 0, 0, 1, 0, 0, 0},    // 3
        {0, 0, 0, 0, 0, 1, 0, 0},    // 4
        {7, 0, 0, 1, 0, 0, 0, 5},    // 5
        {0, 0, 0, 0, 0, 0, 0, 0},    // 6
        {0, 0, -10, 0, 0, 0, 0, 0}}; // 7
    g.loadGraph(graph4);
    CHECK(Algorithms::shortestPath(g, 7, 1) == "-1");
    CHECK(Algorithms::shortestPath(g, 5, 2) == "5->7->2");

    vector<vector<int>> graph5 = {
        // 0  1  2  3  4  5  6  7
        {0, 0, -2, 0, 0, 1, 0, 0}, // 0
        {0, 0, 0, 0, 0, 0, 1, 0},  // 1
        {0, 0, 0, 0, 0, 0, 1, 0},  // 2
        {0, 0, 0, 0, 1, 0, 0, 0},  // 3
        {0, 0, 0, 0, 0, 1, 0, 0},  // 4
        {2, 0, 0, 1, 0, 0, 3, 1},  // 5
        {0, 0, 0, 0, 0, 0, 0, 0},  // 6
        {0, 0, 2, 0, 0, 0, 0, 0}}; // 7
    g.loadGraph(graph5);
    CHECK(Algorithms::shortestPath(g, 5, 2) == "5->0->2");
}

TEST_CASE("Test isContainsCycle undirected unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isContainsCycle(g) == "-1");

    vector<vector<int>> graph3 = {
        //   0  1  2  3  4  5
        {0, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 1, 0, 0, 1, 0}};

    g.loadGraph(graph3);
    CHECK(Algorithms::isContainsCycle(g) == "1->2->3->4->5->1");

    vector<vector<int>> graph4 = {
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isContainsCycle(g) == "-1");
}

TEST_CASE("Test isContainsCycle undirected Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 2, 4},
        {2, 0, 7},
        {4, 7, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph1 = {
        {0, 6, 0},
        {6, 0, 8},
        {0, 8, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isContainsCycle(g) == "-1");

    vector<vector<int>> graph3 = {
        {0, 2, 1, 0, 0, 0},
        {2, 0, 3, 5, 0, 0},
        {1, 3, 0, 0, 1, 0},
        {0, 5, 0, 0, 7, 1},
        {0, 0, 1, 7, 0, 2},
        {0, 0, 0, 1, 2, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph4 = {
        {0, 0, 0, 8, 0, 0},
        {0, 0, 0, -6, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {8, -6, 1, 0, -2, 0},
        {0, 0, 0, -2, 0, 10},
        {0, 0, 0, 0, 10, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "-1");
}

TEST_CASE("Test isContainsCycle directed unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isContainsCycle(g) == "1->3->4->1");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isContainsCycle(g) == "-1");
}

TEST_CASE("Test isContainsCycle directed Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {0, 0, 2},
        {4, 0, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isContainsCycle(g) == "0->1->2->0");

    vector<vector<int>> graph1 = {
        {0, 8, 1, 0, 0},
        {0, 0, 0, 3, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, -4},
        {0, 3, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isContainsCycle(g) == "1->3->4->1");

    vector<vector<int>> graph2 = {
        {0, 10, 8, 0, 0},
        {0, 0, 0, 2, 0},
        {0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isContainsCycle(g) == "-1");
}

TEST_CASE("Test isBipartite undirected unWeighted")
{
    ariel::Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1}.");

    vector<vector<int>> graph1 = {
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0,1,2,4}, B={3,5}.");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0, 1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isBipartite(g) == "-1");
}

TEST_CASE("Test isBipartite undirected Weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, -2, -2},
        {-2, 0, 5},
        {-2, 5, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isBipartite(g) == "-1");

    vector<vector<int>> graph1 = {
        {0, 0, 0, 5, 0, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 0, -1, 0, 0},
        {5, 2, -1, 0, 4, 0},
        {0, 0, 0, 4, 0, 2},
        {0, 0, 0, 0, 2, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0,1,2,4}, B={3,5}.");

    vector<vector<int>> graph2 = {
        {0, 2, 8, 0, 0, 0, 0, 4},
        {1, 0, 1, 3, 0, 0, 0, 0},
        {2, 8, 0, 2, 0, 0, 0, 0},
        {0, 3, 2, 0, -1, 0, 0, 5},
        {0, 0, 0, -1, 0, -5, 6, 0},
        {0, 0, 0, 0, -5, 0, 1, 7},
        {0, 0, 0, 0, 6, 1, 0, 1},
        {4, 0, 0, 5, 0, 7, 1, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isBipartite(g) == "-1");
}

TEST_CASE("Test isBipartite directed unWeighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={1,2,3,5}, B={0,4}.");

    vector<vector<int>> graph1 = {
        // 0  1  2  3  4  5  6  7  8
        {0, 0, 1, 0, 0, 1, 0, 0, 0},  // 0
        {0, 0, 0, 0, 0, 0, 1, 0, 0},  // 1
        {0, 0, 0, 0, 0, 0, 1, 0, 0},  // 2
        {0, 0, 0, 0, 1, 0, 0, 0, 0},  // 3
        {0, 0, 0, 0, 0, 1, 0, 0, 0},  // 4
        {0, 0, 0, 1, 0, 0, 0, 1, 0},  // 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 6
        {0, 0, 1, 0, 0, 0, 0, 0, 1},  // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 8
    g.loadGraph(graph1);
    CHECK(Algorithms::isBipartite(g) == "-1");
}

TEST_CASE("Test isBipartite directed weighted")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 2, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, -1, 0, -5, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6, 0, 0, 0},
        {4, 0, 0, 0, 0, 7, 1, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::isBipartite(g) == "-1");

    vector<vector<int>> graph1 = {
        {0, 0, 3, 20, 0, 0},
        {2, 0, 0, 0, 13, 0},
        {0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={1,2,3,5}, B={0,4}.");
}

TEST_CASE("Test negativeCycle Exists")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, -1, 0},
        {0, 0, -1},
        {-1, 0, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::negativeCycle(g) == "1->2->0->1");

    vector<vector<int>> graph1 = {
        {0, 0, 0, 0},
        {1, 0, -1, 0},
        {0, 0, 0, 1},
        {0, -1, 0, 0}};

    g.loadGraph(graph1);
    CHECK(Algorithms::negativeCycle(g) == "2->3->1->2");
}

TEST_CASE("Test negativeCycle Does not Exist")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0}};
    g.loadGraph(graph0);
    CHECK(Algorithms::negativeCycle(g) == "-1");

    vector<vector<int>> graph1 = {
        {0, 2, 1, 0, 0, 0},
        {2, 0, 3, 5, 0, 0},
        {1, 3, 0, 0, 1, 0},
        {0, 5, 0, 0, 7, 1},
        {0, 0, 1, 7, 0, 2},
        {0, 0, 0, 1, 2, 0}};
    g.loadGraph(graph1);
    CHECK(Algorithms::negativeCycle(g) == "-1");
}

TEST_CASE("Test invalid graph Coluomn missing")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph0));
}

TEST_CASE("Test invalid graph Row missing")
{
    Graph g;
    vector<vector<int>> graph0 = {
        {0, 1, 2},
        {1, 0, 3}};
    CHECK_THROWS(g.loadGraph(graph0));
}

TEST_CASE("Plus")
{
    SUBCASE("graph1 = graph2 + graph3")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        Graph g3;

        g3 = g1 + g2;

        CHECK(g3.getAdjMatrix() == vector<vector<int>>{{0, 1, 0}, {3, 0, 4}, {0, 5, 0}});
    }

    SUBCASE("graph++")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 0, 0, 0, 0}};
        g1.loadGraph(adjmat1);
        g1++;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 2, 3, 0, 0}, {2, 0, 7, 0, 0}, {3, 7, 0, 10, 0}, {0, 0, 10, 0, 0}, {0, 0, 0, 0, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat2);

        g1++;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0, 0}, {0, 0, 4, 8, 0, 0}, {0, 4, 0, 0, 9, 0}, {0, 8, 0, 0, -2, -1}, {0, 0, 9, -2, 0, 2}, {0, 0, 0, -1, 2, 0}});
    }

    SUBCASE("++graph")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 0, 0, 0, 0}};
        g1.loadGraph(adjmat1);

        ++g1;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 2, 3, 0, 0}, {2, 0, 7, 0, 0}, {3, 7, 0, 10, 0}, {0, 0, 10, 0, 0}, {0, 0, 0, 0, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat2);

        ++g1;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0, 0}, {0, 0, 4, 8, 0, 0}, {0, 4, 0, 0, 9, 0}, {0, 8, 0, 0, -2, -1}, {0, 0, 9, -2, 0, 2}, {0, 0, 0, -1, 2, 0}});
    }

    SUBCASE("graph1 += graph2")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        g1 += g2;

        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 1, 0}, {3, 0, 4}, {0, 5, 0}});

        vector<vector<int>> adjmat3 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, -3, 0, 0, 0, 0},
            {0, 0, 1, 2, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, 4, 1},
            {1, 3, 8, -3, 0, 1},
            {2, 0, 0, -2, 1, 0}};
        g2.loadGraph(adjmat4);

        g1 += g2;

        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, -3, 0, 0, 0, 0}, {0, 0, 4, 9, 0, 0}, {0, 6, 0, 0, 16, 0}, {0, 14, 0, 0, 1, -1}, {1, 3, 16, -6, 0, 2}, {2, 0, 0, -4, 2, 0}});
    }
}

TEST_CASE("Minus")
{
    SUBCASE("graph1 = graph2 - graph3")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        Graph g3;

        g3 = g1 - g2;

        CHECK(g3.getAdjMatrix() == vector<vector<int>>{{0, 3, 0}, {1, 0, 2}, {0, 1, 0}});
    }

    SUBCASE("graph--")
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

        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 0, 1, 0, 0}, {0, 0, 5, 0, 0}, {1, 5, 0, 8, 0}, {0, 0, 8, 0, 0}, {0, 0, 0, 0, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 1, 0, 0, 1, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat2);

        g1--;

        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0, 0}, {0, 0, 2, 6, 0, 0}, {0, 2, 0, 0, 7, 0}, {0, 6, 0, 0, -4, -3}, {0, 0, 7, -4, 0, 0}, {0, 0, 0, -3, 0, 0}});
    }

    SUBCASE("--graph")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 0, 0, 0, 0}};
        g1.loadGraph(adjmat1);

        --g1;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 0, 1, 0, 0}, {0, 0, 5, 0, 0}, {1, 5, 0, 8, 0}, {0, 0, 8, 0, 0}, {0, 0, 0, 0, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat2);

        --g1;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0, 0}, {0, 0, 2, 6, 0, 0}, {0, 2, 0, 0, 7, 0}, {0, 6, 0, 0, -4, -3}, {0, 0, 7, -4, 0, 0}, {0, 0, 0, -3, 0, 0}});
    }

    SUBCASE("graph1 -= graph2")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        g1 -= g2;

        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 3, 0}, {1, 0, 2}, {0, 1, 0}});

        vector<vector<int>> adjmat3 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, -3, 0, 0, 0, 0},
            {0, 0, 1, 2, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, 4, 1},
            {1, 3, 8, -3, 0, 1},
            {2, 0, 0, -2, 1, 0}};
        g2.loadGraph(adjmat4);

        g1 -= g2;

        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 3, 0, 0, 0, 0}, {0, 0, 2, 5, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, -7, -3}, {-1, -3, 0, 0, 0, 0}, {-2, 0, 0, 0, 0, 0}});
    }
}

TEST_CASE("Multiplication")
{
    SUBCASE("graph1 = graph2 * graph3")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        Graph g3;
        g3 = g1 * g2;
        CHECK(g3.getAdjMatrix() == vector<vector<int>>{{2, 0, 2}, {0, 4, 0}, {3, 0, 3}});

        vector<vector<int>> adjmat3 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, 3, 8, 0, 3},
            {1, 0, 6, 2, 0},
            {2, -6, 0, 9, 0},
            {1, 0, 9, 0, 2},
            {0, 6, 0, 5, 0}};
        g2.loadGraph(adjmat4);

        g3 = g1 * g2;

        CHECK(g3.getAdjMatrix() == vector<vector<int>>{{5, -12, 6, 20, 0}, {12, -33, 8, 54, 3}, {15, 6, 133, 12, 24}, {18, -54, 0, 81, 0}, {6, 24, 24, 42, 0}});
    }

    SUBCASE("graph1 *= graph2")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, 2, 0}};
        g2.loadGraph(adjmat2);

        g1 *= g2;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{2, 0, 2}, {0, 4, 0}, {3, 0, 3}});

        vector<vector<int>> adjmat3 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, 3, 8, 0, 3},
            {1, 0, 6, 2, 0},
            {2, -6, 0, 9, 0},
            {1, 0, 9, 0, 2},
            {0, 6, 0, 5, 0}};
        g2.loadGraph(adjmat4);
        g1 *= g2;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{5, -12, 6, 20, 0}, {12, -33, 8, 54, 3}, {15, 6, 133, 12, 24}, {18, -54, 0, 81, 0}, {6, 24, 24, 42, 0}});
    }

    SUBCASE("graph1 = graph2 * scalar(int)")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        g2 = g1 * 2;

        CHECK(g2.getAdjMatrix() == vector<vector<int>>{{0, 4, 0}, {4, 0, 6}, {0, 6, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat2);

        g1 = g1 * 4;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 4, 8, 0, 0}, {4, 0, 24, 0, 0}, {8, 24, 0, 36, 0}, {0, 0, 36, 0, 0}, {0, 16, 4, 0, 20}});
    }

    SUBCASE("graph1 *= scalar(int)")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        g1 *= 2;

        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 4, 0}, {4, 0, 6}, {0, 6, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat2);

        g1 *= 4;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 4, 8, 0, 0}, {4, 0, 24, 0, 0}, {8, 24, 0, 36, 0}, {0, 0, 36, 0, 0}, {0, 16, 4, 0, 20}});
    }
}

TEST_CASE("Division")
{
    SUBCASE("graph1 = graph2 / scalar(int)")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        g2 = g1 / 2;

        CHECK(g2.getAdjMatrix() == vector<vector<int>>{{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat2);

        g2 = g1 / 4;
        CHECK(g2.getAdjMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 0, 2, 0}, {0, 0, 2, 0, 0}, {0, 1, 0, 0, 1}});
    }

    SUBCASE("graph1 /= scalar(int)")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        g1 /= 2;

        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 1, 0}, {1, 0, 1}, {0, 1, 0}});

        vector<vector<int>> adjmat2 = {
            {0, 1, 2, 0, 0},
            {1, 0, 6, 0, 0},
            {2, 6, 0, 9, 0},
            {0, 0, 9, 0, 0},
            {0, 4, 1, 0, 5}};
        g1.loadGraph(adjmat2);

        g1 /= 4;
        CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 0, 2, 0}, {0, 0, 2, 0, 0}, {0, 1, 0, 0, 1}});
    }
}

TEST_CASE("Compare")
{
    SUBCASE("graph1 == graph2")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g1 == g2);

        vector<vector<int>> adjmat3 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g2.loadGraph(adjmat4);

        CHECK(g1 == g2);
    }

    SUBCASE("graph1 > graph2")
    {
        Graph g1;

        vector<vector<int>> adjmat1 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;

        vector<vector<int>> adjmat2 = {
            {0, 3, 7, 0},
            {3, 0, 0, 8},
            {7, 0, 0, -3},
            {0, 8, -3, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g1 > g2);
    }

    SUBCASE("graph1 < graph2")
    {
        Graph g1;

        vector<vector<int>> adjmat1 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;

        vector<vector<int>> adjmat2 = {
            {0, 3, 7, 0},
            {3, 0, 0, 8},
            {7, 0, 0, -3},
            {0, 8, -3, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g2 < g1);
    }

    SUBCASE("graph1 >= graph2")
    {
        Graph g1;

        vector<vector<int>> adjmat1 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;

        vector<vector<int>> adjmat2 = {
            {0, 3, 7, 0},
            {3, 0, 0, 8},
            {7, 0, 0, -3},
            {0, 8, -3, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g1 >= g2);

        Graph g3;
        vector<vector<int>> adjmat3 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g3.loadGraph(adjmat3);
        CHECK(g1 >= g3);
        CHECK(g3 >= g1);
    }

    SUBCASE("graph1 <= graph2")
    {
        Graph g1;

        vector<vector<int>> adjmat1 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;

        vector<vector<int>> adjmat2 = {
            {0, 3, 7, 0},
            {3, 0, 0, 8},
            {7, 0, 0, -3},
            {0, 8, -3, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g2 <= g1);

        Graph g3;
        vector<vector<int>> adjmat3 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g3.loadGraph(adjmat3);
        CHECK(g1 <= g3);
        CHECK(g3 <= g1);
    }

    SUBCASE("graph1 != graph2")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, 2, 0},
            {2, 0, 3},
            {0, 1, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g1 != g2);

        vector<vector<int>> adjmat3 = {
            {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, 1, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
             {0, 3, 6, 0, 0, -5},
            {3, 0, 3, 7, 0, 0},
            {6, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, 0, -2},
            {0, 0, 8, -3, 0, 1},
            {-5, 0, 0, -2, 1, 0}};
        g2.loadGraph(adjmat4);

        CHECK(g1 != g2);
    }
}