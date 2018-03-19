//
// Created by Michael on 2018-03-19.
//

#ifndef COEN244_ASS4_ACYCLICGRAPH_H
#define COEN244_ASS4_ACYCLICGRAPH_H

#include "../Graph.h"

struct Edge;

class AcyclicGraph : public Graph {
private:
    int edgeWeightTotal;
    std::vector <std::shared_ptr<Vertex> > nodes;
public:
    virtual bool addVertex(std::shared_ptr<Vertex> ptr);
    virtual bool removeVertex(int);
    virtual bool addEdge(Edge& e, int ,int, int);
    virtual bool removeEdge(int, int);

    virtual bool searchVertex(int);
    virtual bool searchEdge(int);


    // Print Functions
    virtual void printNodes();
    virtual void printNodesWithEdges();
    virtual void printGraphInfo();

    //void printEdgeTracker();


    // Extranneous Functions
    bool searchNodes(int);
    int getIndex(int);
    int getID(int);


    virtual void DFSutil(int);
    virtual bool DFS(std::shared_ptr<Vertex> v, int data, std::vector<int>&);
};


#endif //COEN244_ASS4_ACYCLICGRAPH_H
