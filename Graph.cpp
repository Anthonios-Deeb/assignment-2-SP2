#include "Graph.hpp"
#include <iostream>

using namespace ariel;

// check if the graph is valid or not
void Graph::loadGraph(vector<vector<int>> graph)
{
  if (graph.size() == 0)
  {
    throw invalid_argument("Graph is empty");
  }

  if (graph.size() != graph[0].size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }

  this->adjMat = graph;
}

void Graph::printDetails()
{
  int edges = 0;
  for (auto &i : adjMat)
  {
    for (int j : i)
    {
      if (j != 0)
      {
        edges++;
      }
    }
  }
  cout << "Graph with " << adjMat.size() << " vertices and " << edges << " edges." << endl;
}

void Graph::printMatrix()
{
  for (auto &i : adjMat)
  {
    for (int j : i)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}

vector<vector<int>> Graph::getAdjMatrix()
{
  return adjMat;
}

Graph Graph::operator+(const Graph &other)
{
  vector<vector<int>> newMatrix (this->adjMat.size(), vector<int>(this->adjMat.size(), 0));
  vector<vector<int>> myadjMatrix = this->adjMat;
  vector<vector<int>> otheradjMatrix = other.adjMat;

  if (this->adjMat.size() != otheradjMatrix.size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }
 
  for (size_t i = 0; i < myadjMatrix.size(); i++)
  {
    for (size_t j = 0; j < myadjMatrix[i].size(); j++)
    {
      newMatrix[i][j] = myadjMatrix[i][j] + otheradjMatrix[i][j];
    }
  }



  Graph g;
  g.loadGraph(newMatrix);
  return g;
}

Graph &Graph::operator+=(const Graph &other)
{
  vector<vector<int>> otheradjMatrix = other.adjMat;

  if (this->adjMat.size() != otheradjMatrix.size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }

  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      this->adjMat[i][j] += otheradjMatrix[i][j];
    }
  }

  return *this;
}

Graph &Graph::operator+()
{
  return *this;
}

Graph &Graph::operator++()
{
  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      if (this->adjMat[i][j] != 0)
      {
        this->adjMat[i][j]++;
      }
    }
  }
  return *this;
}

Graph &Graph::operator-(const Graph &other)
{
  vector<vector<int>> newMatrix;
  vector<vector<int>> otheradjMatrix = other.adjMat;

  if (this->adjMat.size() != otheradjMatrix.size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }

  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      newMatrix[i][j] = this->adjMat[i][j] - otheradjMatrix[i][j];
    }
  }

  Graph *g = new Graph();
  g->loadGraph(newMatrix);
  return *g;
}

Graph &Graph::operator-=(const Graph &other)
{
  vector<vector<int>> otheradjMatrix = other.adjMat;

  if (this->adjMat.size() != otheradjMatrix.size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }

  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      this->adjMat[i][j] -= otheradjMatrix[i][j];
    }
  }

  return *this;
}

Graph &Graph::operator-()
{
  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      this->adjMat[i][j] = -this->adjMat[i][j];
    }
  }

  return *this;
}

Graph &Graph::operator--()
{
  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      this->adjMat[i][j]--;
    }
  }

  return *this;
}

// scalar multiplication
Graph &Graph::operator*(int num)
{
  vector<vector<int>> newMatrix;
  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      newMatrix[i][j] = this->adjMat[i][j] * num;
    }
  }

  Graph *g = new Graph();
  g->loadGraph(newMatrix);
  return *g;
}

Graph &Graph::operator*=(int num)
{
  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      this->adjMat[i][j] *= num;
    }
  }

  return *this;
}

// matrix multiplication
Graph &Graph::operator*(const Graph &other)
{
  vector<vector<int>> otheradjMatrix = other.adjMat;
  if (this->adjMat.size() != otheradjMatrix.size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }
  vector<vector<int>> newMatrix;

  int rows1 = this->adjMat.size();
  int cols1 = this->adjMat[0].size();
  int cols2 = otheradjMatrix[0].size();

  std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

  for (int i = 0; i < rows1; ++i)
  {
    for (int j = 0; j < cols2; ++j)
    {
      for (int k = 0; k < cols1; ++k)
      {
        newMatrix[i][j] = this->adjMat[i][k] * otheradjMatrix[k][j];
      }
    }
  }

  Graph *g = new Graph();
  g->loadGraph(newMatrix);
  return *g;
}

Graph &Graph::operator*=(const Graph &other)
{
  vector<vector<int>> otheradjMatrix = other.adjMat;
  if (this->adjMat.size() != otheradjMatrix.size())
  {
    throw invalid_argument("Invalid graph: The graph is not a square matrix.");
  }

  int rows1 = this->adjMat.size();
  int cols1 = this->adjMat[0].size();
  int cols2 = otheradjMatrix[0].size();

  std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

  for (int i = 0; i < rows1; ++i)
  {
    for (int j = 0; j < cols2; ++j)
    {
      for (int k = 0; k < cols1; ++k)
      {
        this->adjMat[i][j] = this->adjMat[i][k] * otheradjMatrix[k][j];
      }
    }
  }

  return *this;
}

Graph &Graph::operator/(int num)
{
  vector<vector<int>> newMatrix;
  if (num == 0)
  {
    throw invalid_argument("Invalid argument: Division by zero.");
  }

  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      newMatrix[i][j] = this->adjMat[i][j] / num;
    }
  }

  Graph *g = new Graph();
  g->loadGraph(newMatrix);
  return *g;
}

Graph &Graph::operator/=(int num)
{
  if (num == 0)
  {
    throw invalid_argument("Invalid argument: Division by zero.");
  }

  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      this->adjMat[i][j] /= num;
    }
  }

  return *this;
}

bool Graph::operator==(const Graph &other)
{
  return this->adjMat == other.adjMat;
}

bool Graph::operator>(const Graph &other)
{
  size_t rowsA = this->adjMat.size();
  size_t colsA = this->adjMat[0].size();
  size_t rowsB = other.adjMat.size();
  size_t colsB = other.adjMat[0].size();

  for (size_t i = 0; i <= rowsA - rowsB; ++i)
  {
    for (size_t j = 0; j <= colsA - colsB; ++j)
    {
      bool found = true;
      for (size_t k = 0; k < rowsB; ++k)
      {
        for (size_t l = 0; l < colsB; ++l)
        {
          if (this->adjMat[i + k][j + l] != other.adjMat[k][l])
          {
            found = false;
            break;
          }
        }
        if (!found)
        {
          break;
        }
      }
      if (found)
      {
        return true;
      }
    }
  }
  return false;
}

bool Graph::operator>=(const Graph &other)
{
  return *this > other || *this == other;
}

bool Graph::operator<(const Graph &other)
{
  size_t rowsA = this->adjMat.size();
  size_t colsA = this->adjMat[0].size();
  size_t rowsB = other.adjMat.size();
  size_t colsB = other.adjMat[0].size();

  for (size_t i = 0; i <= rowsA - rowsB; ++i)
  {
    for (size_t j = 0; j <= colsA - colsB; ++j)
    {
      bool found = true;
      for (size_t k = 0; k < rowsB; ++k)
      {
        for (size_t l = 0; l < colsB; ++l)
        {
          if (this->adjMat[i + k][j + l] != other.adjMat[k][l])
          {
            found = false;
            break;
          }
        }
        if (!found)
        {
          break;
        }
      }
      if (found)
      {
        return false;
      }
    }
  }
  return true;
}

bool Graph::operator<=(const Graph &other)
{
  return *this < other || *this == other;
}

bool Graph::operator!=(const Graph &other)
{
  return !(*this == other);
}

// Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]
ostream &ariel::operator<<(ostream &os, const Graph &g)
{
  for (auto &i : g.adjMat)
  {
    os << "[";
    for (int j : i)
    {
      os << j << ", ";
    }
    os << "], ";
  }
  
  return os;
}