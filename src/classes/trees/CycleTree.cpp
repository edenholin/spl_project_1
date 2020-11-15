#include "../../../include/Tree.h"

CycleTree::CycleTree(int rootLabel, int currCycle): // constructor
Tree(rootLabel), currCycle(currCycle)
{}


CycleTree::CycleTree(const CycleTree &other): // copy constructor
Tree(other), currCycle(other.currCycle)
{}

// copy assignment operator
CycleTree &CycleTree::operator=(const CycleTree &other) {
    if(this != &other)
    {
        this->clean();
        node = other.node;
        currCycle = other.currCycle;
        children = other.children;
    }
    return (*this);
}
// move constructor
CycleTree::CycleTree(CycleTree &&other)
        :Tree(std::move(other)),currCycle(other.currCycle)
{

}
// move assignment
CycleTree &CycleTree::operator=(CycleTree &&other)
{
    if(this != &other)
    {
        this->clean();
        node = other.node;
        currCycle = other.currCycle;
        children = std::move(other.children);
    }
    return (*this);
}


Tree * CycleTree::clone() const
{
    return new CycleTree((*this));
}


int CycleTree::traceTree()
{
    Tree* currentTree = this;
    int cycleCount = currCycle;
    while (cycleCount>0&&currentTree->hasChildren())
    {
        currentTree = currentTree->getLeftChild();
        cycleCount--;
    }
    return currentTree->getNodeInd();
}