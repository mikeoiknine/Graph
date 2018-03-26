//
// Created by Michael on 2018-03-20.
//


#include "UndirectedGraph.h"
#include <algorithm>


// Vertex Functions
bool UndirectedGraph::addVertex(std::shared_ptr<Vertex> ptr) {
    nodes.push_back(std::move(ptr));
    return true;
}
bool UndirectedGraph::removeVertex(int data) {
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
bool UndirectedGraph::searchVertex(int id) {
    return (this->getIndex(id)) < 0 ? false : true;
}


// Edge Functions
bool UndirectedGraph::addEdge(Edge &e, int src, int dest, int weight) {
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

    // Add edge to destination node pointing to source node
    Edge *a = new Edge(e.id);
    a->edge = nodes[getIndex(src)];
    a->weight = weight;

    // Add edge from destination to this edge
    nodes[getIndex(dest)]->addEdgeToVertex(*a);


    // Increment total weight of edges in graph (for overloading '>' '<' operators)
    edgeWeightTotal += weight;

    return true;
}
bool UndirectedGraph::removeEdge(int nodeNum, int desNodeNum) {
    for(auto& e : nodes){
        if(e->getID() == nodeNum){
            edgeWeightTotal -= e->removeEdgeFromVertex(desNodeNum);
            for(auto& a : nodes){
                if(a->getID() == desNodeNum){
                    a->removeEdgeFromVertex(nodeNum);
                    return true;
                }
            }

        }
    }
}
bool UndirectedGraph::searchNodes(int id) {
    for(auto& i : nodes){
        if(id == i->getID()){
            return true;
        }
    }

    return false;
}
bool UndirectedGraph::searchEdge(int id) {
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
void UndirectedGraph::DFSutil(int data){
    int i = 0;
    std::vector<int> visited;
    while(!DFS(nodes[i], data, visited) || i == nodes.size()){ i++; visited.clear(); };
}
bool UndirectedGraph::DFS(std::shared_ptr<Vertex> v, int data, std::vector<int>& visited) {
    std::cout << "DATA          = " << data << std::endl;
    std::cout << "VERTEX DATA   = " << v->getData() << std::endl;
    if(data == v->getData()){
        std::cout << v->getID() << std::endl;
        return true;
    }

    visited.push_back(v->getID());

    for(auto &e : v->returnEdgeArray()){
        std::cout << "LOOP" << std::endl;
        if(!(std::find(visited.begin(), visited.end(), e.edge.lock()->getID()) != visited.end())){
            std::cout << v->getID()  << "->" ; std::cout.flush();
            return DFS(nodes[getIndex(e.edge.lock()->getID())], data, visited);
        }
    }

    return false;
}


// Getter Functions
int UndirectedGraph::getID(int data) {
    for(int _id = 0; _id < nodes.size(); _id++){
        if(data == nodes[_id]->getData()){
            return nodes[_id]->getID();
        }
    }
}
int UndirectedGraph::getIndex(int id) {
    for(int i = 0; i < nodes.size(); i++){
        if(id == nodes[i]->getID()){
            return i;
        }
    }
    return -1;
}


// Print Functions
void UndirectedGraph::printNodes() {
    std::cout.flush();
    for(auto& e : nodes){
        std::cout << std::endl
                  << "<---- Node " << e->getID() << " ----> ";
        std::cout << std::endl
                  << "Data ----------> " << e->getData();
        std::cout << std::endl << std::endl;
    }
}
void UndirectedGraph::printNodesWithEdges() {
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
void UndirectedGraph::printGraphInfo() {
    std::cout << "No. Nodes ---------------- " << nodes.size() << std::endl;
    std::cout << "Edge Weight Tot. --------- " << edgeWeightTotal << std::endl;
}
bool UndirectedGraph::toString() {
    if(nodes.size() <= 0)
        return false;

    // Using '=====' instead of ; in order to keep DFSUtil for reuse
    for(auto &e : nodes){
        DFSutil(e->getData());
        std::cout << "=======" << std::endl;
    }

    return true;

}

// Bonus implementations
bool UndirectedGraph::addVertexArray(std::vector<std::shared_ptr<Vertex> >& v){
    for(auto &e : v){
        addVertex(e);
    }
}
bool UndirectedGraph::addEdgeArray(std::vector<Edge> &v, std::vector<int> src,
                               std::vector<int> dest, std::vector<int> weight) {
    for(int i = 0; i < v.size(); i++){
        addEdge(v[i], src[i], dest[i], weight[i]);
    }
}


// Destructors
bool UndirectedGraph::clean() {
    edgeWeightTotal = 0;
    nodes.clear();
}


// Operators
bool UndirectedGraph::operator==(const UndirectedGraph &graph) {
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
UndirectedGraph& UndirectedGraph::operator=(const UndirectedGraph &RightGraph) {
    if(&RightGraph != this){
        this->nodes.clear();
        this->edgeWeightTotal = RightGraph.edgeWeightTotal;

        for(auto e : RightGraph.nodes){
            nodes.push_back(std::make_shared<Vertex>(*e));
        }

        return *this;

    }
}

UndirectedGraph UndirectedGraph::operator++(int) {
    UndirectedGraph result(*this);
    ++(*this);
    return result;
}
UndirectedGraph &UndirectedGraph::operator++() {
    for(auto& e : this->nodes){
        auto & v = e->returnEdgeArray();
        for(auto& i : v){
            i.weight++;
            this->edgeWeightTotal++;
        }
    }
    return *this;
}
UndirectedGraph &UndirectedGraph::operator+(const UndirectedGraph &graph) {
    // Append nodes of graph 1 to graph 2
    this->nodes.insert(this->nodes.end(), graph.nodes.begin(), graph.nodes.end());
    this->edgeWeightTotal += graph.edgeWeightTotal;
    return *this;
}
std::ostream &operator<<(std::ostream & out, const UndirectedGraph &graph) {
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
bool UndirectedGraph::operator>(const UndirectedGraph &graph) {
    return (this->edgeWeightTotal > graph.edgeWeightTotal);
}
bool UndirectedGraph::operator<(const UndirectedGraph &graph) {
    return (this->edgeWeightTotal < graph.edgeWeightTotal);
}



