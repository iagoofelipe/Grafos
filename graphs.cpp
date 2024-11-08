#include "graphs.h"
#include <algorithm>
#include <iostream>
#include <sstream>

namespace graph
{

SimpleNode::SimpleNode(const char *_name)
    : _name(_name)
{
}

const char* SimpleNode::getName() {
    std::stringstream ss;
    ss << "<Node " << _name << ">";
    return ss.str().c_str();
}

std::vector<SimpleNode*>* SimpleNode::getEdges() {
    return &_edges;
}

void SimpleNode::displayName() {
    std::cout << getName() << std::endl;
}

void SimpleNode::displayEdges() {
    if(hasEdges()) {
        std::cout << getName() << ":\n";
    } else {
        std::cout << getName() << " has no edges!\n";
        return;
    }

    for(auto const& edge : _edges) {
        std::cout << "\t" << edge->getName() << std::endl;
    }
}

void SimpleNode::addEdge(SimpleNode* _node) {
    if(std::find(_edges.begin(), _edges.end(), _node) != _edges.end())
        std::cout << "the node " << _node->getName() << "already is in the edges queue!\n";
    else
        _edges.push_back(_node);
}

bool SimpleNode::hasEdges() {
    return !_edges.empty();
}

}
