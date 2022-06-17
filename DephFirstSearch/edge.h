#include <string>

#pragma once

/*  --  Struct Edge --  */
class Edge {
    private:
        std::string src;    // string source; beginning of the directed connection
        std::string dest;   // string destination; end of the directed connection
        
    public:
        Edge(std::string src, std::string dest, int weight=0);    // Constructor
        int weight;
        const std::string& getSrc() const;          // getter function for std::string src
        void setSrc(std::string src);               // setter funciton for std::string src
        const std::string& getDest() const;         // getter function for std::string dest
        void setDest(std::string dest);             // setter function for std::string dest

};
