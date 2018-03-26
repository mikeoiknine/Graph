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
    nodes[getIndex(src)]->addEdgeToVertex(e);

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
void DirectGraph::DFSutil(int data){
    std::vector<int> visited;
    DFS(nodes[0], data, visited);
}
bool DirectGraph::DFS(std::shared_ptr<Vertex> v, int data, std::vector<int>& visited) {
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

// Destructors
bool DirectGraph::clean() {
    edgeWeightTotal = 0;
    nodes.clear();
}

// Bonus implementations
bool DirectGraph::addVertexArray(std::vector<std::shared_ptr<Vertex> >& v){
        for(auto &e : v){
            addVertex(e);
        }
}

bool DirectGraph::addEdgeArray(std::vector<Edge> &v, std::vector<int> src,
                               std::vector<int> dest, std::vector<int> weight) {
    for(int i = 0; i < v.size(); i++){
        addEdge(v[i], src[i], dest[i], weight[i]);
    }
}

// Operators
bool DirectGraph::operator==(const DirectGraph &graph) {
    if(nodes.size() != graph.nodes.size())
        return false;
    if(edgeWeightTotal != graph.edgeWeightTotal)
        return false;

    for(int i = 0; i < nodes.size(); i++){
        if(nodes[i]->getID() != graph.nodes[i]->getID())
            return false;
        if(nodes[i]->getData() != graph.nodes[i]->getData())
            return false;
    }

    return true;
}
DirectGraph& DirectGraph::operator=(const DirectGraph &RightGraph) {
    if(&RightGraph != this){
        this->nodes.clear();
        this->edgeWeightTotal = RightGraph.edgeWeightTotal;

        for(auto e : RightGraph.nodes){
            nodes.push_back(std::make_shared<Vertex>(*e));
        }

        return *this;

    }
}
DirectGraph DirectGraph::operator++(int) {
    DirectGraph result(*this);
    ++(*this);
    return result;
}
DirectGraph &DirectGraph::operator++() {
    for(auto& e : this->nodes){
        auto & v = e->returnEdgeArray();
        for(auto& i : v){
            i.weight++;
            this->edgeWeightTotal++;
        }
    }
    return *this;
}
std::ostream &operator<<(std::ostream & out, const DirectGraph &graph) {
    for(auto& i : graph.nodes){
        out << std::endl
            << "<---- Node " << i->getID() << " ----> "
            << std::endl
            << "Data ----------> " << i->getData()
            << std::endl;
        i->printEdgeArray();
    }

    return out;
}
bool DirectGraph::operator>(const DirectGraph &graph) {
    return (this->edgeWeightTotal > graph.edgeWeightTotal);
}
bool DirectGraph::operator<(const DirectGraph &graph) {
    return (this->edgeWeightTotal < graph.edgeWeightTotal);
}
DirectGraph &DirectGraph::operator+(const DirectGraph &graph) {
    // Append nodes of graph 1 to graph 2
    this->nodes.insert(this->nodes.end(), graph.nodes.begin(), graph.nodes.end());
    this->edgeWeightTotal += graph.edgeWeightTotal;
    return *this;
}

