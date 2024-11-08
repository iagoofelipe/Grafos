#include "graph.h"
#include <iostream>

int main() {

    GraphWeight g({
        { "A", "B", 4 },
        { "A", "C", 3 },
        { "C", "B", 5 },
        { "B", "D", 4 },
        { "D", "C", 4.12 },
    });

    g.displayNodes(true);

    return 0;
}

// #include <iostream>
// #include <map>
// #include <sstream>
// #include <vector>

// using namespace std;





// void addEdges(vector<edge> edges) {
//     for(auto& v : edges) {
//         v.source->addEdge(v.destiny, v.weight);
//     }
// }

// int main() {

//     Node 
//         *pnA = new Node("A"),
//         *pnB = new Node("B"),
//         *pnC = new Node("C"),
//         *pnD = new Node("D")
//         ;
//     addEdges({
//         { pnA, pnB, 4 },
//         { pnA, pnC, 3 },
//         { pnC, pnB, 5 },
//         { pnB, pnD, 4 },
//         { pnD, pnC, 4.12 },
//     });

//     pnA->displayEdges();
//     pnB->displayEdges();
//     pnC->displayEdges();
//     pnD->displayEdges();


//     delete pnA;
//     delete pnB;
//     delete pnC;
//     delete pnD;

//     return 0;
// }