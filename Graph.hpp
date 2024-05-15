#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <iostream>
using namespace std;

namespace ariel
{
  class Graph
  {
  public:
    Graph() = default;
    ~Graph() = default;

    Graph(const Graph&) = default;
    void loadGraph(vector<vector<int> > graph);
    void printDetails();
    void printMatrix();
    vector<vector<int>> getAdjMatrix();

    Graph operator+(const Graph &g);

    Graph &operator+=(const Graph &g);
    Graph &operator+();
    Graph &operator++();
    Graph operator++(int);

    Graph operator-(const Graph &g);
    Graph &operator-=(const Graph &g);
    Graph &operator-();
    Graph &operator--();

    Graph &operator*(int);
    Graph &operator*=(int);
    Graph &operator*(const Graph &g);
    Graph &operator*=(const Graph &g);
    Graph &operator/(int);
    Graph &operator/=(int);

    bool operator==(const Graph &g);
    bool operator>(const Graph &g);
    bool operator>=(const Graph &g);
    bool operator<(const Graph &g);
    bool operator<=(const Graph &g);
    bool operator!=(const Graph &g);

   

  private:
    vector<vector<int>> adjMat;
    friend ostream &operator<<(ostream &os,const Graph &g);
  }; 
}

#endif