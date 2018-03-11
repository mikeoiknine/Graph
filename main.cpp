#include <iostream>
#include <memory>
#include "Vertex.h"
#include "Graph.h"
#include "DirectGraph.h"


int main() {
    Graph *graph = new DirectGraph();
    bool isRunning = true;

    while(isRunning) {

        char __choice;
        int __data, __src, __dest, __weight, __id;

        std::cout << "a ------ addVertex" << std::endl
                  << "b ------ removeVertex" << std::endl
                  << "c ------ addEdge" << std::endl
                  << "d ------ removeEdge" << std::endl
                  << "e ------ DFS" << std::endl
                  << "f ------ searchIfVertexExists" << std::endl
                  << "g ------ searchIfEdgeExists" << std::endl
                  << "w ------ printGraphInfo" << std::endl
                  << "x ------ printNodes" << std::endl
                  << "y ------ printNodesWithEdges" << std::endl
                  << "z ------ exit"
                  << std::endl;

        std::cin >> __choice;

        if (__choice == 'a') {
            std::cout << "\nData: "; std::cin >> __data;
            std::shared_ptr<Vertex> ptr = std::make_shared<Vertex>(__data);
            std::cout << (graph->addVertex(ptr) ? "Success" : "Failed") << std::endl;
        }

        if (__choice == 'b') {
            std::cout << "\nData: "; std::cin >> __data;
            std::cout << (graph->removeVertex(__data) ? "Success" : "Failed") << std::endl;
        }

        if (__choice == 'c') {
            Edge *e = new Edge();
            std::cout << "\nSource: "; std::cin >> __src;
            std::cout << "\nDestination: "; std::cin >> __dest;
            std::cout << "\nWeight: "; std::cin >> __weight;
            std::cout << (graph->addEdge(*e, __src, __dest, __weight) ? "Success" : "Failed") << std::endl;
        }

        if (__choice == 'd') {
            std::cout << "\nSource: "; std::cin >> __src;
            std::cout << "\nDestination: "; std::cin >> __dest;
            std::cout << (graph->removeEdge(__src, __dest) ? "Succes" : "Failed") << std::endl;
        }

        if(__choice == 'e'){
            std::cout << "\nData: "; std::cin >> __data;
            graph->DFSutil(__data);
            std::cout << std::endl;
        }

        if(__choice == 'f'){
            std::cout << "\nID: "; std::cin >> __id;
            std::cout << (graph->searchVertex(__id) ? "Vertex exists" : "Vertex does not exist") << std::endl;
            std::cout << std::endl;
        }

        if(__choice == 'g'){
            std::cout << "\nID: "; std::cin >> __id;
            std::cout << (graph->searchEdge(__id) ? "Edge exists" : "Edge does not exist") << std::endl;
            std::cout << std::endl;
        }

        if(__choice == 'w'){
            std::cout << std::endl;
            graph->printGraphInfo();
            std::cout << std::endl;
        }

        if(__choice == 'x'){
            std::cout << std::endl;
            graph->printNodes();
            std::cout << std::endl;
        }

        if(__choice == 'y'){
            std::cout << std::endl;
            graph->printNodesWithEdges();
            std::cout << std::endl;
        }

        if(__choice == 'z'){
            isRunning = false;
        }

    }

    return 0;
}