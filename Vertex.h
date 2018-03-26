//
// Created by Michael on 2018-03-09.
//

#ifndef COEN244_ASS4_VERTEX_H
#define COEN244_ASS4_VERTEX_H

#include <iostream>
#include <memory>
#include <vector>


class DirectGraph;
class Vertex;

struct Edge {
    int weight;
    int id;
    std::weak_ptr< Vertex > edge;
    Edge();
    Edge(int);
    //~Edge(){std::cout << std::endl << "Edge Destructor called" << std::endl;}
};

class Vertex {
    int data;
    int id;
    std::vector<Edge> edgeArray;
public:
    std::vector<Edge>& returnEdgeArray();

    Vertex();
    Vertex(int);
    Vertex(int, int);
    int getID();
    int getData();
    void addEdgeToVertex(Edge &e);
    int removeEdgeFromVertex(int); // Returns edge weight
    void printEdgeArray();

    bool searchEdgeForDuplicates(int);

    int removeAllEdgesToNode(int);

    Vertex& operator=(const Vertex&);
};


#endif //COEN244_ASS4_VERTEX_H
