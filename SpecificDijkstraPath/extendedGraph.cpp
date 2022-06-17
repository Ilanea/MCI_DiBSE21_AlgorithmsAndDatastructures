#include "extendedGraph.h"


Graph::Graph() {                                            //  Default Constructor
    this->vertices = std::vector<std::string>(0);           //  Empty Vector for this->vertices
    this->adjacencyMatrix.resize(0, std::vector<int>(0));   //  0x0 Matrix for this->adjacencyMatrix
}

/*  --
    Constructor with params
--  */
Graph::Graph(const std::vector<std::string>& vertices, const std::vector<Edge>& edges) {
    this->vertices = vertices;                                                                  //  definition of this->vertex through parameter vertices (type: std::vector<std::string>)
    this->adjacencyMatrix.resize(vertices.size(), std::vector<int>(this->vertices.size()));     //  creation of an NxN Matrix, based on the size of vertices

    for(unsigned int i = 0; i < edges.size(); i++) {
        insertEdge(edges[i]);                   //  edges are added one by one, utilizing the insertEdge()-Function
    }
}

/*  --  /
Function to insert a vertex into the Graph;
    - takes one argument of type std::string that represents a vertex
    - returns void
/   --  */
void Graph::insertVertex(const std::string& vertex) {
    if(this->resolveVertex(vertex) != -1) {         /*  --  */
        std::cerr << "Vertex already in Graph!\n";  /*  Calls this->resolveVertex to check if a given vertex is already in the Graph. Returns with an error, if this is the case.   */
        return;                                     /*  --  */
    }
    this->vertices.push_back(vertex);               //  adds a vertetx via the push_back function provided by std::vector
    this->adjacencyMatrix.resize(this->vertices.size(), std::vector<int>(this->vertices.size()));   //  resizes the adjacencyMatrix to the new size
    for(unsigned int i = 0; i < this->vertices.size(); i++) {        /*  --  */
        adjacencyMatrix[i].resize(this->vertices.size());   /*  resizes every "sub" vector of the matrix to the new size    */
    }                                                       /*  --  */
}

/*  --  /
Function to delete a vertex from the Graph;
    - takes one argument of type std::string that represents a vertex
    - returns void
/   --  */
void Graph::deleteVertex(const std::string& vertex) {
    int index = this->resolveVertex(vertex);
    if(index == -1) {                               /*  --  */
        std::cerr << "Vertex not found\n";          /*  Calls this->resolveVertex to check if a given vertex is already in the Graph. Returns with an error, if this is the case.   */
        return;                                     /*  --  */
    }
    this->vertices.erase(this->vertices.begin() + index);   //  erases the vertex at position "index" from this->vertices

    this->adjacencyMatrix.erase(this->adjacencyMatrix.begin() + index);             //  erases the entries from the adjacencyMatrix at "column" position "index"
    for(unsigned int i = 0; i < this->adjacencyMatrix[0].size(); i ++) {                     /*  --  */
        this->adjacencyMatrix[i].erase(this->adjacencyMatrix[i].begin() + index);   /*  erases the entries from the adjacencyMatrix in every "row" */
    }                                                                               /*  --  */
}


/*  --  /
Function to insert an Edge
    - takes one argument of type Edge that represents an edge
    - returns void
/   --  */
void Graph::insertEdge(const Edge& edge) {
    int col = this->resolveVertex(edge.getSrc());        //  resolves the src of the edge to the index within the adjacencyMatrix
    int row = this->resolveVertex(edge.getDest());       //  resolves the dest of the edge to the index within the adjacencyMatrix
    if(col == -1 || row == -1) {                    /*  --  */
        std::cerr << "Vertex not found!\n";         /*  Calls this->resolveVertex to check if a given vertex is already in the Graph. Returns with an error, if this is the case.   */
        return;                                     /*  --  */
    }

    this->adjacencyMatrix[col][row]= edge.weight;   //  sets the value of the adjacencyMatrix at position [col][row] to the weight of the edge
    this->adjacencyMatrix[row][col]= edge.weight;   //  sets the value of the adjacencyMatrix at position [col][row] to the weight of the edge
}

/*  --  /
Function to delete an Edge
    - takes one argument of type Edge that represents an edge
    - returns void
/   --  */
void Graph::deleteEdge(const Edge& edge) {
    int col = this->resolveVertex(edge.getSrc());        //  resolves the src of the edge to the index within the adjacencyMatrix
    int row = this->resolveVertex(edge.getDest());       //  resolves the dest of the edge to the index within the adjacencyMatrix
    if(col == -1 || row == -1) {                    /*  --  */
        std::cerr << "Vertex not found!\n";         /*  Calls this->resolveVertex to check if a given vertex is already in the Graph. Returns with an error, if this is the case.   */
        return;                                     /*  --  */
    }
    this->adjacencyMatrix[col][row]= 0;             //  sets the value of the adjacencyMatrix at position [col][row] to 0
}

/*  --  /
Function to check whether vertex v2 is adjacent to vertex v1
    - takes one argument of type Edge that represents an edge
    - returns void
/   --  */
bool Graph::adjacent(const std::string& vertex1, const std::string& vertex2) {
    int indexVertex1 = this->resolveVertex(vertex1);
    int indexVertex2 = this->resolveVertex(vertex2);
    if(indexVertex1 == -1 || indexVertex2 == -1) {
        std::cerr << "Vertex not found!\n";
        return false;
    }
    //  As adjacency is an equivalency relation, we need to check for a possible relation in both direction.
    //  This can be achieved by swapping the the position specifications of the adjacencyMatrix (from [indexVertex1][indexVertex2]
    //  to [indexVertex2][indexVertex1]).
    if(this->adjacencyMatrix[indexVertex1][indexVertex2] != 0 || this->adjacencyMatrix[indexVertex2][indexVertex1] != 0) {
        return true;    //  if a connection (in any direction) is found, return true
    } else {
        return false;   //  else, return false
    }
}

/*  --  /
Function that returns an std::vector of std::string representing the neighbouring vertices of the parameter std::string vertex.
Other than adjacent, neighbourhood is a directed relationship, which means that a vertex "A" can be the neighbour of "B", but
this does not automatically imply that "B" is the neighbour of "A".
    - takes one argument of type std::string that represents a vertex
    - returns a std::vector of std::string
/   --  */
std::vector<std::string> Graph::neighbours(const std::string& vertex) {
    int indexVertex = this->resolveVertex(vertex);                          //  resolves the vertex to the index within the adjacencyMatrix
    std::vector<std::string> resVector = {};                                //  initializes an empty std::vetor of std::string
    for(unsigned int i = 0; i < this->adjacencyMatrix[indexVertex].size(); i++) {    /*  Loops through all entries of the subvector of adjacencyMatrix[indexVertex] */
        if(this->adjacencyMatrix[indexVertex][i] != 0) {                    /*  and checks if  the entry at position [indexVertex][i] is not 0. */
            resVector.push_back(this->vertices[i]);                         /*  If the condition is fulfilled, add the vertex (name) to the result vector resVector */
        }
    }
    return resVector;
}

std::vector<std::string> Graph::neighboursBefore(std::string &vertex) {
    int indexVertex = this->resolveVertex(vertex);
    std::vector<std::string> tempVector = { };

    for (unsigned int i = 0; i < this->adjacencyMatrix[indexVertex].size(); i++){
        if (this->adjacencyMatrix[i][indexVertex] != 0){
            tempVector.push_back(this->vertices[i]);
        }
    }

    return tempVector;
}

/*  --  /
Function that prints the current Graph's adjacencyMatrix.
    - prints the Graph by utilizing std::cout
    - returns void
/   --  */
void Graph::printGraph() {
    std::cout << "--------------------------------------------\n";
    std::cout << "\t\t";
    for(unsigned int i = 0; i < this->vertices.size(); i++) {
        std::cout << this->vertices[i] << "\t";
    }
    std::cout << "\n";
    for(unsigned int i=0; i < this->vertices.size(); i++) {
        std::cout << this->vertices[i] << "\t-->\t";
        for(unsigned int j = 0; j < this->vertices.size(); j++) {
            std::cout << this->adjacencyMatrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "--------------------------------------------\n";
};

/*  --  /
Function that resolves a parameter std::string name and returns it's index within the this->vertices vector;
between vertices of type std::string and the corresponding index (in the adjacencyMatrix) of type int.
    - takes one argument of type std::string that represents a vertex
    - returns an int representing the vertex's index in the adjacencyMatrix;
    - function returns -1 in case the resolution of the name is unsuccessful
/   --  */
int Graph::resolveVertex(const std::string& vertexName) {
    for(unsigned int i = 0; i < this->vertices.size(); i++) {
        if(this->vertices[i] == vertexName) {
            return i;
        }
    }
    return -1;
}

// Djikstra Path & Helperfunktionen
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
int Graph::minDistance(int *dist, bool *sptSet) {
    int min = INT_MAX, min_index;

    for(unsigned int v = 0; v < vertices.size(); v++){
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

void Graph::performDijkstraPath(std::string sourceVertex, std::string targetVertex) {
    int src = this->resolveVertex(sourceVertex);
    int dest = this->resolveVertex(targetVertex);
    bool sptSet[vertices.size()];

    int dist[vertices.size()];
    int Path[vertices.size()];

    for(unsigned int i = 0; i < vertices.size(); i++){
        dist[i] = INT_MAX, sptSet[i] = false;
    }
    dist[src] = 0;
    Path[0] = src;

    for(unsigned int count = 0; count < vertices.size() - 1; count++){
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for(unsigned int v = 0; v < vertices.size(); v++){
            if(!sptSet[v] && this->adjacencyMatrix[u][v] && dist[u] != INT_MAX && dist[u] + this->adjacencyMatrix[u][v] < dist[v]){
                dist[v] = dist[u] + this->adjacencyMatrix[u][v];
            }
        }
    }
    this->printDijkstraPath(dist, Path, 0, src, dest);
}

void Graph::printDijkstraPath(int *dist, int *path, int indexOfPath, int src, int dest) {
    if(dest == src){
        for(int i = indexOfPath-1; i>=0; i--){
            if( i == 0){
                std::cout << this->vertices[path[i]];
                std::cout << "; Gesamter Zollbetrag: " << dist[path[i]] << std::endl;
            }
            else
            {
                int Weight;
                Weight = this->adjacencyMatrix[path[i]][path[i-1]];
                std::cout << this->vertices[path[i]] << " -(" << Weight << ")->" << " ";
            }
        }
        return;
    }
    if(indexOfPath == 0){
        path[indexOfPath] = dest;
        indexOfPath++;
    }
    std::vector<std::string> neighbours = this->neighboursBefore(this->vertices[dest]);

    int value;
    int minVal = 0;
    int minIndex;
    for(std::vector<std::string>::iterator it = neighbours.begin(); it != neighbours.end(); ++it){

        int index_two = this->resolveVertex(*it);

        value = dist[index_two] + this->adjacencyMatrix[index_two][dest];

        if ((minVal == 0) || value  < minVal){
            minVal = value;
            minIndex = index_two;
        }
    }
    path[indexOfPath] = minIndex;
    indexOfPath = indexOfPath + 1;

    this->printDijkstraPath(dist, path, indexOfPath, src, minIndex);
}
