//
// Created by Michael on 2018-03-09.
//

#include "Vertex.h"

unsigned int dynamicID = 1;
unsigned int dynamicEdgeID = 1;

Edge::Edge() {
    id = dynamicEdgeID++;
}

Vertex::Vertex() {
    data = 0;
    id = dynamicID++;
}


Vertex::Vertex(int d) {
    data = d;
    id = dynamicID++;
}


std::vector<Edge> &Vertex::returnEdgeArray() {
    return edgeArray;
}


int Vertex::getData() {
    return data;
}

int Vertex::getID() {
    return id;
}

int Vertex::removeEdgeFromVertex(int desNodeNum) {
    int _edgeW = 0;
    // Find index of Destination in edgeArray of vertex and delete it
    for(int i = 0; i < edgeArray.size(); i++){
        if(desNodeNum == edgeArray[i].edge.lock()->id){
            // Store weight of edge
            _edgeW = edgeArray[i].weight;

            std::vector<Edge>::iterator it;
            it = (edgeArray.begin() + i);
            edgeArray.erase(it);

            // return Edge weight
            return _edgeW;
        }
    }
}

void Vertex::printEdgeArray() {
    for(int i = 0; i < edgeArray.size(); i++){
        std::cout << "  |--> Connected to node - No.: " << edgeArray[i].edge.lock()->getID() << " with weight of " << edgeArray[i].weight;
        std::cout << std::endl;
    }

}

void Vertex::addEdgeToVertex(Edge &e, int) {
    this->edgeArray.push_back(e);
}

int Vertex::removeAllEdgesToNode(int vertexID) {
    std::cout << "In remove all edges " << std::endl;
    int tempWeight;
    std::vector<Edge>::iterator it;
    for(int i = 0; i < edgeArray.size(); i++){
        if(edgeArray[i].edge.lock()->id == vertexID){
            tempWeight = edgeArray[i].weight;
            it = (edgeArray.begin() + i);
            edgeArray.erase(it);
            return tempWeight;
        }
    }

    return 0;
}


bool Vertex::searchEdgeForDuplicates(int destID) {
    for(int i = 0; i < edgeArray.size(); i++){
        if(edgeArray[i].edge.lock()->id == destID){
            return true; // There is a duplicate
        }
    }
    return false;
}
