//
// Created by Michael on 2018-03-09.
//

#ifndef COEN244_ASS4_GRAPH_H
#define COEN244_ASS4_GRAPH_H


#include <memory>
#include "Vertex.h"

class Graph {
public:
    virtual bool addVertex(std::shared_ptr<Vertex> ptr)=0;
    virtual bool removeVertex(int)=0;
    virtual bool addEdge(Edge& e,int ,int, int)=0;
    virtual bool removeEdge(int, int)=0;

    virtual bool searchVertex(int)=0;
    virtual bool searchEdge(int)=0;


    virtual void printNodes()=0;
    virtual void printNodesWithEdges()=0;
    virtual void printGraphInfo()=0;

    virtual bool toString()=0;
    virtual bool clean()=0;

    virtual void DFSutil(int)=0;
    virtual bool DFS(std::shared_ptr<Vertex> v, int data, std::vector<int>&)=0;


    // Bonus implementations
    virtual bool addVertexArray(std::vector< std::shared_ptr<Vertex> >&)=0;
    virtual bool addEdgeArray(std::vector<Edge>&, std::vector<int>, std::vector<int>, std::vector<int>)=0;

};


#endif //COEN244_ASS4_GRAPH_H
