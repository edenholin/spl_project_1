#include "../../../include/Agent.h"

Virus::Virus(int nodeInd): Agent(),nodeInd(nodeInd)
{

}

Virus::Virus(const Virus& other):
Agent(),nodeInd(other.nodeInd)
{

}

void Virus::act(Session& session)
{
    Graph g = session.getGraph();
    g.infectNode(nodeInd);
    std::vector<int> vec = g.getNeighbours(nodeInd);
    bool found = false;
    if(! vec.empty())
    {
        for(int i=0; !found && i<vec.size(); i++)
        {
            if(! g.isInfected(vec[i]))
            {
                Agent * spread = new Virus(vec[i]);
                session.addAgent(*spread); // add the new virus as an agent to agent queue
                found = true;
            }
        }
    }
}

Agent * Virus::clone() const
{
    return new Virus(*this);
}

