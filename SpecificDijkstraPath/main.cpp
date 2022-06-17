
#include "extendedGraph.h"
#include "edge.h"
#include <vector>   /*  type vector  */
#include <string>   /*  type string  */
#include <iostream> /*  cout, cerr  */
#include <sstream>  /*  type stringstream to easily concat a result string  */

int main() {
    /*  Creation of Graph   */
    std::vector<std::string> vertices = {"London", "Mailand", "Wien", "Madrid", "Rom", "Paris", "Amster", "Moskau", "Berlin", "Lyon"};
    std::vector<Edge> edges = {
        {"London", "Mailand", 2}, {"London", "Wien", 2},
        {"Mailand", "London", 2}, {"Mailand", "Wien", 6}, {"Mailand", "Madrid", 5},
        {"Wien", "London", 2}, {"Wien", "Mailand", 6}, {"Wien", "Rom", 4}, {"Wien", "Paris", 5},
        {"Madrid", "Mailand", 5}, {"Madrid", "Rom", 5}, {"Madrid", "Lyon", 4},
        {"Rom", "Wien", 4}, {"Rom", "Madrid", 5}, {"Rom", "Moskau", 3}, {"Rom", "Lyon", 4},
        {"Paris", "Wien", 5}, {"Paris", "Amster", 1}, {"Paris", "Moskau", 1}, {"Paris", "Lyon", 2},
        {"Amster", "Paris", 1}, {"Amster", "Moskau", 1},
        {"Moskau", "Rom", 3}, {"Moskau", "Paris", 1}, {"Moskau", "Amster", 1}, {"Moskau", "Berlin", 2},
        {"Berlin", "Moskau", 2}, {"Berlin", "Lyon", 2},
        {"Lyon", "Madrid", 3}, {"Lyon", "Rom", 4}, {"Lyon", "Paris", 2}, {"Lyon", "Berlin", 2},
    };
    Graph g(vertices, edges);
    g.printGraph();

    g.performDijkstraPath("London", "Berlin");

    /*  insertVertices  */
    // g.insertVertex("D");
    // g.insertVertex("H");
    // g.printGraph();

    /*  insertEdges */
    // g.insertEdge({"C", "D"});
    // g.insertEdge({"F", "H"});
    // g.insertEdge({"G", "H"});
    // g.insertEdge({"D", "H"});
    // g.printGraph();

    /*  deleteEdges */
    // g.deleteEdge({"D", "H"});
    // g.printGraph();

    /*  Delete Vertices */
    // g.deleteVertex("C");
    // g.printGraph();
    
    /*  Adjacency   */
    // std::cout << "Adjacent B --> A? " << g.adjacent("B", "A") << "\n";
    // std::cout << "Adjacent A --> B? " << g.adjacent("A", "B") << "\n";
    // std::cout << "Adjacent A --> H? " << g.adjacent("A", "H") << "\n";

    /*  Neighbourhood   */
    // std::cout << "\n";
    // std::cout << "Neighbours of B: ";
    // vectorToString(g.neighbours("B"));
    // std::cout << "Neighbours of A: ";
    // vectorToString(g.neighbours("A"));
    // std::cout << "Neighbours of H: ";
    // vectorToString(g.neighbours("H"));
}

void vectorToString(std::vector<std::string> vector) {
    for(unsigned int i = 0; i < vector.size(); i++){
        std::cout << vector[i] << "\t";
    }
    std::cout << "\n";
}
