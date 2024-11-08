#include "graphs.h"

int main() {

    graph::SimpleNode n1("N1"), n2("N2");

    n1.addEdge(&n2);
    n2.addEdge(&n1);

    n1.displayEdges();
    n2.displayEdges();

    return 0;
}