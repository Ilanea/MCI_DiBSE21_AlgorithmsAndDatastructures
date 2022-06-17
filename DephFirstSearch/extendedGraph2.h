#include <vector>   /*  type vector  */
#include <string>   /*  type string  */
#include <iostream> /*  cout, cerr  */
#include <sstream>  /*  type stringstream to easily concat a result string  */
#include <limits.h> /*  INT_MAX */

#include "edge.h"


#pragma once

void vectorToString(std::vector<std::string> vector);



/*  --  Class Graph --  */
class Graph {
private:
    std::vector<std::string> vertices;                  //  vector connecting vertices with indicies; needed for name resolution

public:
    Graph();                                            //  default constructor
    Graph(const std::vector<std::string>& vertices, const std::vector<Edge>& edges);  //  param. constructor
    std::vector<std::vector<int>> adjacencyMatrix;      //  vector of vectors containing integers (the adjacency matrix)

    /*  --
        Resolves a given string of a vertex and returns its position in the
        adjacencyMatrix (as integer). Returns -1 if name could not be resolved,
        which indicates the the name was not found.
    --  */
    int resolveVertex(const std::string& name);
    void printGraph();    //  prints out the graph with vertices and the adjacencyMatrix

    /*  --
        Graph Manipulation Functions
    --  */
    void insertVertex(const std::string& vertex);
    void deleteVertex(const std::string& vertex);
    void insertEdge(const Edge& edge);
    void deleteEdge(const Edge& edge);
    bool adjacent(const std::string& vertex1, const std::string& vertex2);

    // Naechster Nachbar und vorheriger Nachbar
    std::vector<std::string> neighbours(const std::string& vertex);
    std::vector<std::string> neighboursBefore(std::string &vertex);

    // Spezifischer Djikstra Pfad und Helferfunktionen
    int minDistance(int dist[], bool sptSet[]);
    void printDijkstraPath(int dist[], int path[], int indexOfPath, int src, int dest);
    void performDijkstraPath(std::string sourceVertex, std::string targetVertex);

    // Tiefensuche
    void depthSearch(int i, bool visited[]);
    void depthFirstSearch(std::string vertex);


    int getEdgeWeight(std::string sourceVertex, std::string targetVertex);
    void setEdgeWeight(std::string sourceVertex, std::string targetVertex, int weight);


};

