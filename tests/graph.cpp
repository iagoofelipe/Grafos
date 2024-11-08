#include "graph.h"
#include <stack>

Node::Node(std::string name) :
    name(name)
{
}

std::string Node::getName() {
    std::stringstream ss;
    ss << "<Node " << name << ">";
    return ss.str();
}

void Node::displayName() {
    std::cout << getName() << std::endl;
}

void Node::displayEdges() {
    if(!hasEdges()) {
        std::cout << getName() << " has no edges!" << "\n";
        return;
    }

    std::cout << "Edges " << getName() << ":\n";
    for(auto const& node : edges) {
        std::cout << "\t" << node->getName() << std::endl;
    }
    std::cout << std::endl;
}

void Node::addEdge(Node *node) {
    edges.push_back(node);
}

bool Node::hasEdges() {
    return !edges.empty();
}

void NodeWeight::addEdge(Node *node, float weight) {
    edges[node] = weight;
}

void NodeWeight::displayEdges() {
    if(!hasEdges()) {
        std::cout << getName() << " has no edges!" << "\n";
        return;
    }

    std::cout << "Edges " << getName() << ":\n";
    for(auto const& [key, val] : edges) {
        std::cout << "\t" << key->getName() << " weight: " << val << std::endl;
    }
    std::cout << std::endl;
}

GraphWeight::GraphWeight() {}
    
GraphWeight::GraphWeight(edges values) {
    for(auto const& edge : values) {
        NodeWeight
            *source = getNode(edge.source),
            *destiny = getNode(edge.destiny);
        
        source->addEdge(destiny, edge.weight);
    }
}

GraphWeight::~GraphWeight() {
    for(auto& node : _nodes)
        delete node;
}

// retorna o ponteiro para Node com o respectivo nome, caso o mesmo não exista, um objeto será criado
NodeWeight* GraphWeight::getNode(std::string name) {
    NodeWeight *node;

    if(_mapNodes.count(name)) { // caso exista um elemento com esse nome
        node = _mapNodes[name];
    } else { // gerando, casa não exista
        node = new NodeWeight(name);
        _mapNodes[name] = node;
        _nodes.push_back(node);
    }

    return node;
}

const w_nodes* GraphWeight::getNodes() {
    return &_nodes;
}

void GraphWeight::displayNodes(bool show_edges) {
    std::cout << "Nodes:\n";
    for(auto const& node : _nodes) {
        node->displayName();
        if(show_edges) {
            if(node->hasEdges())
                node->displayEdges();
            else
                std::cout << "This node has no edges!\n\n";
        }
    }
}

w_nodes* GraphWeight::getShorterPath(std::string start, std::string end) {
    if(!_mapNodes.count(start)) {
        std::cout << "'" << start << "' is not a valid start!\n";
        return nullptr;
    }

    w_nodes *path = new w_nodes;
    // std::stack<> stack;

    return path;
}