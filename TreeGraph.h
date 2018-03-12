//
// Created by mikeo on 2018-03-11.
//

#ifndef COEN244_ASS4_TREEGRAPH_H
#define COEN244_ASS4_TREEGRAPH_H


#include "Graph.h"

class TreeGraph : public Graph {
protected:
    std::weak_ptr<Vertex> rootNode;

public:
    virtual bool addVertex(std::shared_ptr<Vertex> ptr);
};


#endif //COEN244_ASS4_TREEGRAPH_H
