#include <string>
#include <vector>

namespace graph
{

class SimpleNode
{
public:
    SimpleNode(const char* _name);
    
    const char* getName();
    std::vector<SimpleNode*>* getEdges();
    void displayName();
    void displayEdges();
    
    bool hasEdges();
    void addEdge(SimpleNode* _node);

protected:
    const char* _name;
    std::vector<SimpleNode*> _edges;
};



class SimpleGraph
{

};

}