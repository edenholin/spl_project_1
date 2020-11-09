#include "../../include/Graph.h"
#include "iostream"


Graph::Graph():
edges(std::vector<std::vector<int>> ()),
infectedQueue(std::deque<int>())
{}

Graph::Graph(std::vector<std::vector<int>> matrix):
edges(matrix),
infectedQueue(std::deque<int>())
{
    printGraph();
}

Graph::Graph(const Graph &other)
:edges(other.edges),infectedQueue(other.infectedQueue)
{
}

void Graph::printGraph()
{
    // Print input info to console
    std::cout << "graph:" << std::endl;
    for (int i = 0, r=(edges).size() ; i < r ; i++)
    {
        for (int j = 0, c=(edges)[i].size(); j<c; j++) {
            std::cout << (edges)[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool Graph::isInfectedEmpty()
{
    return infectedQueue.empty();
}

void Graph::infectNode(int nodeInd)
{
    if(!isInfected(nodeInd))
        infectedQueue.push_back(nodeInd);
}

int Graph::dequeueInfected()
{
    if(!infectedQueue.empty())
    {
        int nodeTemp = infectedQueue.front();
        infectedQueue.pop_front();
        return nodeTemp;
    }
    return -1;
}

bool Graph::isInfected(int nodeInd)
{
    for(int currNode : infectedQueue)
        if(currNode == nodeInd)
            return true;
    return false;
}

std::vector<std::vector<int>>* Graph::getEdgesCopy() {
    return new std::vector<std::vector<int>>(edges);
}

std::vector<int> Graph::getNeighbours(int nodeInd) const {
    size_t rowInd = nodeInd;
    auto neighbours = std::vector<int>();
    if(rowInd>=0&&rowInd<edges.size())
    {
        for(size_t colInd=0,len=edges.size();colInd<len;colInd++)
        {
            if(edges[nodeInd][colInd]==1)
                neighbours.push_back(colInd);
        }
    }
    return neighbours;
}

unsigned int Graph::getVerticesCount() const
{
    return edges.size();
}

std::deque<int>* Graph::getInfectedCopy()
{
    return new std::deque<int>(infectedQueue);
}

void Graph::removeEdge(int firstNode, int secondNode)
{
    //using size_t to compare with .size() without warnings
    size_t node1 = firstNode;
    size_t node2 = secondNode;
    if(node1>=0&&node1<edges.size()&&node2>=0&&node2<edges.size())
    {
        edges[firstNode][secondNode] = 0;
        edges[secondNode][firstNode] = 0;
    }
}

void Graph::removeNode(int node)
{
//    std::cout << "IN removeNode:"<< node << std::endl;
    //using size_t to compare with .size() without warnings
    size_t tNode = node;
    if(tNode>=0&&tNode<edges.size())
    {
        for(int row=0,len=edges.size();row<len;row++)
            edges[row][node]=0;
        for(int col=0,len=edges.size();col<len;col++)
            edges[node][col]=0;
    }
//    printGraph();
}


