#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph();
    Graph(const Graph& other);
    ~Graph();
    std::vector<std::vector<int>> * getEdgesCopy();
    std::vector<int> getNeighbours(int nodeInd) const;
    unsigned int getVerticesCount() const;
    
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
private:
    std::vector<std::vector<int>> edges;
};

#endif