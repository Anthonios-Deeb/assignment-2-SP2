//324933993
//anthoniosdb@gmail.com
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

vector<vector<int>> Graph::getAdjMatrix()
{
  return adjMat;
}

Graph Graph::operator+(const Graph &other)
{
  vector<vector<int>> newMatrix(this->adjMat.size(), vector<int>(this->adjMat.size(), 0));
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

Graph Graph::operator++(int)
{
  Graph g = *this;

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
  return g;
}

Graph Graph::operator-(const Graph &other)
{
  vector<vector<int>> newMatrix(this->adjMat.size(), vector<int>(this->adjMat.size(), 0));
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

  Graph g;
  g.loadGraph(newMatrix);
  return g;
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
      if (this->adjMat[i][j] != 0)
      {
        this->adjMat[i][j]--;
      }
    }
  }
  return *this;
}

Graph Graph::operator--(int)
{
  Graph g = *this;

  for (size_t i = 0; i < this->adjMat.size(); i++)
  {
    for (size_t j = 0; j < this->adjMat[i].size(); j++)
    {
      if (this->adjMat[i][j] != 0)
      {
        this->adjMat[i][j]--;
      }
    }
  }
  return g;
}

Graph &Graph::operator*(int num)
{
  vector<vector<int>> newMatrix (this->adjMat.size(), vector<int>(this->adjMat[0].size(), 0));
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
    for (size_t j = 0; j < this->adjMat[0].size(); j++)
    {
      this->adjMat[i][j] *= num;
    }
  }

  return *this;
}

// matrix multiplication
Graph &Graph::operator*(const Graph &other)
{
  if(this->adjMat.size() != other.adjMat.size())
  {
    throw invalid_argument("Invalid graph: The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
  }
  
  vector<vector<int>> newMatrix(this->adjMat.size(), vector<int>(other.adjMat[0].size(), 0));
  vector<vector<int>> otheradjMatrix = other.adjMat;

  for (size_t i = 0; i < this->adjMat.size(); ++i)
  {
    for (size_t j = 0; j < otheradjMatrix[0].size(); ++j)
    {
      for (size_t k = 0; k < this->adjMat[0].size(); ++k)
      {
        newMatrix[i][j] += this->adjMat[i][k] * otheradjMatrix[k][j];
      }
    }
  }

  Graph *g = new Graph();
  g->loadGraph(newMatrix);
  return *g;
}

Graph &Graph::operator*=(const Graph &other)
{
  if(this->adjMat.size() != other.adjMat.size())
  {
    throw invalid_argument("Invalid graph: The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
  }
  
  vector<vector<int>> newMatrix(this->adjMat.size(), vector<int>(other.adjMat[0].size(), 0));
  vector<vector<int>> otheradjMatrix = other.adjMat;

  for (size_t i = 0; i < this->adjMat.size(); ++i)
  {
    for (size_t j = 0; j < otheradjMatrix[0].size(); ++j)
    {
      for (size_t k = 0; k < this->adjMat[0].size(); ++k)
      {
        newMatrix[i][j] += this->adjMat[i][k] * otheradjMatrix[k][j];
      }
    }
  }

  this->loadGraph(newMatrix);
  return *this;
}

Graph &Graph::operator/(int num)
{
  vector<vector<int>> newMatrix (this->adjMat.size(), vector<int>(this->adjMat[0].size(), 0));
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
      bool found = false;
      for (size_t k = 0; k < rowsB; ++k)
      {
        for (size_t l = 0; l < colsB; ++l)
        {
          if (this->adjMat[i + k][j + l] != other.adjMat[k][l])
          {
            found = true;
            break;
          }
        }
        if (found)
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

bool Graph::operator<=(const Graph &other)
{
  return *this < other || *this == other;
}

bool Graph::operator!=(const Graph &other)
{
  return !(*this == other);
}

ostream &ariel::operator<<(ostream &os, const Graph &g)
{
  for (auto &i : g.adjMat)
  {
    os << "[";
    for (int j : i)
    {
      os << j << ",";
    }
    os << "]";
    os << endl;
  }

  return os;
}
