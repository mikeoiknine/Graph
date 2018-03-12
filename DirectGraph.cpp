//
// Created by Michael on 2018-03-09.
//


#include "DirectGraph.h"
#include <algorithm>


// Vertex Functions
bool DirectGraph::addVertex(std::shared_ptr<Vertex> ptr) {
    nodes.push_back(std::move(ptr));
    return true;
}
bool DirectGraph::removeVertex(int data) {
    // Find the ID of desired node and return the index in graph vector
    int _index, _id;
    _id = getID(data);
    _index = getIndex(_id);

    // Remove all edges pointing to this vertex across the graph
    for(auto& e : nodes){
        if(nodes[_index] != e){
            edgeWeightTotal -= e->removeAllEdgesToNode(_id);
        }
    }

    // Delete the Vertex
    std::vector< std::shared_ptr<Vertex> >::iterator it;
    it = (nodes.begin() + _index);
    nodes.erase(it);

    return true;
}
bool DirectGraph::searchVertex(int id) {
    return (this->getIndex(id)) < 0 ? false : true;
}


// Edge Functions
bool DirectGraph::addEdge(Edge &e, int src, int dest, int weight) { // Problem with indexing after deletion of node
    // Check if src and dest are nodes in graph
    if(!searchNodes(src))
        return false;
    if(!searchNodes(dest))
        return false;

    // Check if this edge already exists
    if(nodes[getIndex(src)]->searchEdgeForDuplicates(dest))
        return false;

    // Set edge to point to destination
    e.edge = nodes[getIndex(dest)];

    // Set edge weight
    e.weight = weight;

    // Add edge to this nodes edgeArray
    nodes[getIndex(src)]->addEdgeToVertex(e, dest);

    // Add Edge to map with the Vertex being pointed to as the key (ID's of both)
    //edgeTracker[e.edge.lock()->getID()].push_back(e.id);

    // Increment total weight of edges in graph (for overloading '>' '<' operators)
    edgeWeightTotal += weight;

    return true;
}
bool DirectGraph::removeEdge(int nodeNum, int desNodeNum) {
    for(auto& e : nodes){
        if(e->getID() == nodeNum){
            edgeWeightTotal -= e->removeEdgeFromVertex(desNodeNum);
            return true;
        }
    }
}
bool DirectGraph::searchNodes(int id) {
    for(auto& i : nodes){
        if(id == i->getID()){
            return true;
        }
    }

    return false;
}
bool DirectGraph::searchEdge(int id) {
    for(auto e : nodes){
        for(auto i : e->returnEdgeArray()){
            if(i.id == id){
                return true;
            }
        }
    }
    return false;
}

// Depth First Search Algorithm
void DirectGraph::DFSutil(int data) {
    std::vector<int> visited;
    DFS(nodes[0], data, visited);
}
bool DirectGraph::DFS(std::shared_ptr<Vertex> v, int data, std::vector<int> visited) {
    if(data == v->getData()){
        std::cout << v->getID() << std::endl;
        return true;
    }

    visited.push_back(v->getID());

    for(auto &e : v->returnEdgeArray()){
        if(!(std::find(visited.begin(), visited.end(), e.edge.lock()->getID()) != visited.end())){
            std::cout << v->getID()  << "->" ; std::cout.flush();
            return DFS(nodes[getIndex(e.edge.lock()->getID())], data, visited);
        }
    }

    return false;
}


// Getter Functions
int DirectGraph::getID(int data) {
    for(int _id = 0; _id < nodes.size(); _id++){
        if(data == nodes[_id]->getData()){
            return nodes[_id]->getID();
        }
    }
}
int DirectGraph::getIndex(int id) {
    for(int i = 0; i < nodes.size(); i++){
        if(id == nodes[i]->getID()){
            return i;
        }
    }
    return -1;
}


// Print Functions
void DirectGraph::printNodes() {
    std::cout.flush();
    for(auto& e : nodes){
        std::cout << std::endl
                  << "<---- Node " << e->getID() << " ----> ";
        std::cout << std::endl
                  << "Data ----------> " << e->getData();
        std::cout << std::endl << std::endl;
    }
}
void DirectGraph::printNodesWithEdges() {
    for(int e = 0; e < nodes.size(); e++){
        std::cout << std::endl
                  << "<---- Node " << nodes[e]->getID() << " ----> ";
        std::cout << std::endl
                  << "Data ----------> " << nodes[e]->getData();
        std::cout << std::endl;
        nodes[e]->printEdgeArray();
    }

    //printEdgeTracker();

}
void DirectGraph::printGraphInfo() {
    std::cout << "No. Nodes ---------------- " << nodes.size() << std::endl;
    std::cout << "Edge Weight Tot. --------- " << edgeWeightTotal << std::endl;
}
bool DirectGraph::toString() {
    if(nodes.size() <= 0)
        return false;

    // Using '=====' instead of ; in order to keep DFSUtil for reuse
    for(auto &e : nodes){
        DFSutil(e->getData());
        std::cout << "=======" << std::endl;
    }

    return true;

}

/*void DirectGraph::printEdgeTracker() {
    std::cout << std::endl;
    std::map<int, std::vector<int> >::iterator it;
    for(it = edgeTracker.begin(); it != edgeTracker.end(); it++){
        std::cout << it->first << std::endl;
        for(auto it2 : it->second){
            std::cout << "|->Pointed to by edge No.: " << it2 << std::endl;
        }
    }

}*/

// Destructors
bool DirectGraph::clean() {
    nodes.clear();
}






