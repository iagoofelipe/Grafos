#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>

class Node
{
public:
    Node(std::string name);

    std::string getName();
    void displayName();
    void displayEdges();
    void addEdge(Node *node);
    bool hasEdges();

private:
    std::string name;
    std::vector<Node*> edges;
};

class NodeWeight : public Node
{

public:
    using Node::Node;

    void addEdge(Node *node, float weight);
    void displayEdges();

protected:
    std::map<Node*, float> edges;
};


struct edge {
    std::string source;
    std::string destiny;
    float weight = 1;
};

using edges = std::vector<edge>;
using w_nodes = std::vector<NodeWeight*>;

class GraphWeight
{

public:
    GraphWeight();
    GraphWeight(edges values);

    ~GraphWeight();

    // retorna o ponteiro para Node com o respectivo nome, caso o mesmo não exista, um objeto será criado
    NodeWeight* getNode(std::string name);
    const w_nodes* getNodes();
    void displayNodes(bool show_edges = false);
    w_nodes* getShorterPath(std::string start, std::string end = "");

private:
    std::map<std::string, NodeWeight*> _mapNodes;
    w_nodes _nodes;
};