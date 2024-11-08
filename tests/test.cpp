#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>

class Node
{
public:
    Node(std::string name) :name(name) {}

    std::string getName() {
        std::stringstream ss;
        ss << "<Node " << name << ">";
        return ss.str();
    }

    void displayName() {
        std::cout << getName() << std::endl;
    }

    void displayEdges() {
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

    void addEdge(Node *node) {
        edges.push_back(node);
    }

    bool hasEdges() { return !edges.empty(); }

protected:
    std::string name;
    std::vector<Node*> edges;
};

class NodeWeight : public Node
{

public:
    using Node::Node;

    void addEdge(Node *node, float weight) {
        edges[node] = weight;
    }

    void displayEdges() {
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

protected:
    std::map<Node*, float> edges;
};

struct edge {
    std::string source;
    std::string destiny;
    float weight = 1;
};

using w_edges = std::vector<w_edge>;
using w_nodes = std::vector<NodeWeight*>;

struct w_edge {
    std::string source;
    std::string destiny;
    float weight = 1;
};

using w_edges = std::vector<w_edge>;
using w_nodes = std::vector<NodeWeight*>;

class GraphWeight
{

public:
    GraphWeight();
    GraphWeight(w_edges values) {

    }

    ~GraphWeight();

    // retorna o ponteiro para Node com o respectivo nome, caso o mesmo não exista, um objeto será criado
    NodeWeight* getNode(std::string name) {
        
    }

    const w_nodes* getNodes();
    void displayNodes(bool show_edges = false);
    w_nodes* getShorterPath(std::string start, std::string end = "");

private:
    std::map<std::string, NodeWeight*> _mapNodes;
    w_nodes _nodes;
};

int main() {
    NodeWeight n1("N1");
    Node n2("N2");

    n1.addEdge(&n2, 10);
    n2.addEdge(&n1);

    n1.displayEdges();
    n2.displayEdges();
}