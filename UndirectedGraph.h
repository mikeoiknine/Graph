//
// Created by Michael on 2018-03-20.
//

#ifndef COEN244_ASS4_UNDIRECTEDGRAPH_H
#define COEN244_ASS4_UNDIRECTEDGRAPH_H


#include "Graph.h"

class UndirectedGraph : public Graph {
private:
    int edgeWeightTotal;
    std::vector< std::shared_ptr<Vertex> > nodes;
public:
    virtual bool addVertex(std::shared_ptr<Vertex> ptr);
    virtual bool removeVertex(int);
    virtual bool addEdge(Edge& e, int ,int, int);
    virtual bool removeEdge(int, int);

    virtual bool searchVertex(int);
    virtual bool searchEdge(int);

    virtual bool clean();

    // Print Functions
    virtual void printNodes();
    virtual void printNodesWithEdges();
    virtual void printGraphInfo();
    virtual bool toString();

    //void printEdgeTracker();


    // Extranneous Functions
    bool searchNodes(int);
    int getIndex(int);
    int getID(int);


    virtual void DFSutil(int);
    virtual bool DFS(std::shared_ptr<Vertex> v, int data, std::vector<int>&);


    // Bonus implementations
    virtual bool addVertexArray(std::vector< std::shared_ptr<Vertex> >&);
    virtual bool addEdgeArray(std::vector<Edge>&, std::vector<int>, std::vector<int>, std::vector<int>);


    // Operators
    bool operator==(const UndirectedGraph&);
    bool operator>(const UndirectedGraph&);
    bool operator<(const UndirectedGraph&);
    UndirectedGraph& operator=(const UndirectedGraph&);
    UndirectedGraph& operator+(const UndirectedGraph&);
    UndirectedGraph operator++(int);
    UndirectedGraph& operator++();
    friend std::ostream& operator<<(std::ostream&, const UndirectedGraph&);
};


#endif //COEN244_ASS4_UNDIRECTEDGRAPH_H
