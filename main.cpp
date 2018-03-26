#include <iostream>
#include <memory>
#include "Vertex.h"
#include "Graph.h"
#include "DirectGraph.h"
#include "AcyclicGraph.h"
#include "UndirectedGraph.h"

void OperatorTest(int type){
    /*
     * In order to keep the code a little cleaner, I only test
     * the operators on DirectedGraph, though it is important
     * to Note that the operator functions are implemented in ALL
     * graph types. The full testable code can be found commented below
     *
     */
    DirectGraph dGraph1;
    DirectGraph dGraph2;
    DirectGraph dGraph3;
    DirectGraph dGraph4;

    // Set up graph 1
    dGraph1.addVertex(std::make_shared<Vertex>(1, 3));
    dGraph1.addVertex(std::make_shared<Vertex>(2, 4));
    dGraph1.addVertex(std::make_shared<Vertex>(3, 5));

    auto *edge1 = new Edge;
    auto *edge2 = new Edge;
    dGraph1.addEdge(*edge1, 1, 3, 2);
    dGraph1.addEdge(*edge2, 2, 3, 5);

    // Set up Graph 2
    dGraph2.addVertex(std::make_shared<Vertex>(1, 3));
    dGraph2.addVertex(std::make_shared<Vertex>(2, 4));
    dGraph2.addVertex(std::make_shared<Vertex>(3, 5));

    auto *edge3 = new Edge;
    auto *edge4 = new Edge;
    dGraph2.addEdge(*edge3, 1, 3, 2);
    dGraph2.addEdge(*edge4, 2, 3, 5);

    // Set up Graph 4
    dGraph4.addVertex(std::make_shared<Vertex>(4, 6));
    dGraph4.addVertex(std::make_shared<Vertex>(5, 7));
    dGraph4.addVertex(std::make_shared<Vertex>(6, 8));

    auto *edge5 = new Edge;
    auto *edge6 = new Edge;
    dGraph4.addEdge(*edge5, 4, 5, 6);
    dGraph4.addEdge(*edge6, 5, 6, 8);

    bool repeat = true;
    char __choice;
    // Was short on time, so all operators are tested statically
    while(repeat){
        std::cout << std::endl;
        std::cout << "Which Operator Would You Like To Tests? " << std::endl;
        std::cout << "a ------ '=='" << std::endl
                  << "b ------ '='" << std::endl
                  << "c ------ '+'" << std::endl
                  << "d ------ '>'" << std::endl
                  << "e ------ '<'" << std::endl
                  << "f ------ '++'" << std::endl
                  << "z ------ exit to main menu"
                  << std::endl;

        std::cin >> __choice;

        switch(__choice){
            case 'a':
                std::cout << "      ===========BEFORE==========" << std::endl;
                std::cout << "Graph 1: " << std::endl;
                std::cout << dGraph1 << std::endl;
                std::cout << "Graph 2: " << std::endl;
                std::cout << dGraph2 << std::endl;
                std::cout << "      ==========COMPARE==========" << std::endl;
                std::cout << "Graph 1 == Graph 2 -> ";
                std::cout << ((dGraph1 == dGraph2) ? "True" : "False") << std::endl;
                break;

            case 'b':
                std::cout << "      ===========BEFORE==========" << std::endl;
                std::cout << "Graph 1: " << std::endl;
                std::cout << dGraph1 << std::endl;

                std::cout << "Graph 3: " << std::endl;
                std::cout << dGraph3 << std::endl;

                std::cout << "      ===========AFTER==========" << std::endl;
                std::cout << "Assigning Graph 1 to Graph 3: ";
                dGraph3 = dGraph1;
                std::cout << "Graph 3 After Assignments: " << std::endl;
                std::cout << dGraph3 << std::endl;
                break;

            case 'c':
                std::cout << "      ===========BEFORE==========" << std::endl;
                std::cout << "Graph 1: " << std::endl;
                std::cout << dGraph1 << std::endl;

                std::cout << "Graph 4: " << std::endl;
                std::cout << dGraph4 << std::endl;

                std::cout << std::endl;
                std::cout << "      ===========AFTER==========" << std::endl;
                std::cout << "Graph 1 + Graph 4 " << std::endl;
                std::cout << (dGraph1 + dGraph4) << std::endl;
                break;

            case 'd':
                std::cout << "      ===========BEFORE==========" << std::endl;
                std::cout << "Graph 1: " << std::endl;
                std::cout << dGraph1 << std::endl;

                std::cout << "Graph 4: " << std::endl;
                std::cout << dGraph4 << std::endl;

                std::cout << "      ==========COMPARE==========" << std::endl;
                std::cout << "Graph 1 > Graph 4 -> ";
                std::cout << ((dGraph1 > dGraph4) ? "True" : "False") << std::endl;
                break;

            case 'e':
                std::cout << "      ===========BEFORE==========" << std::endl;
                std::cout << "Graph 1: " << std::endl;
                std::cout << dGraph1 << std::endl;

                std::cout << "Graph 4: " << std::endl;
                std::cout << dGraph4 << std::endl;

                std::cout << "      ==========COMPARE==========" << std::endl;
                std::cout << "Graph 1 < Graph 4 -> ";
                std::cout << ((dGraph1 < dGraph4) ? "True" : "False") << std::endl;
                break;

            case 'f':
                std::cout << "      ===========BEFORE==========" << std::endl;
                std::cout << "Graph 2: " << std::endl;
                std::cout << dGraph2 << std::endl;

                std::cout << "      ===========AFTER==========" << std::endl;
                std::cout << "(Graph 2)++ " << std::endl;
                std::cout << dGraph2++ << std::endl;

                std::cout << "      ===========BEFORE==========" << std::endl;
                std::cout << "Graph 2: " << std::endl;
                std::cout << dGraph2 << std::endl;

                std::cout << "      ===========AFTER==========" << std::endl;
                std::cout << "++(Graph 2) " << std::endl;
                std::cout << ++dGraph2 << std::endl;

            case 'z':
                repeat = false;
                break;

            default: break;

        }



    }
/*
    if(type == 1){
        DirectGraph dGraph1;
        DirectGraph dGraph2;
        DirectGraph dGraph3;
        DirectGraph dGraph4;

        std::cout << "Overloaded Operator Tests:" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "Operator '==' " << std::endl;


        // Set up graph 1
        dGraph1.addVertex(std::make_shared<Vertex>(1, 3));
        dGraph1.addVertex(std::make_shared<Vertex>(2, 4));
        dGraph1.addVertex(std::make_shared<Vertex>(3, 5));

        auto *edge1 = new Edge;
        auto *edge2 = new Edge;
        dGraph1.addEdge(*edge1, 1, 3, 2);
        dGraph1.addEdge(*edge2, 2, 3, 5);

        // Set up Graph 2
        dGraph2.addVertex(std::make_shared<Vertex>(1, 3));
        dGraph2.addVertex(std::make_shared<Vertex>(2, 4));
        dGraph2.addVertex(std::make_shared<Vertex>(3, 5));

        auto *edge3 = new Edge;
        auto *edge4 = new Edge;
        dGraph2.addEdge(*edge3, 1, 3, 2);
        dGraph2.addEdge(*edge4, 2, 3, 5);

        // Set up Graph 4
        dGraph4.addVertex(std::make_shared<Vertex>(4, 6));
        dGraph4.addVertex(std::make_shared<Vertex>(5, 7));
        dGraph4.addVertex(std::make_shared<Vertex>(6, 8));

        auto *edge5 = new Edge;
        auto *edge6 = new Edge;
        dGraph4.addEdge(*edge5, 4, 5, 2);
        dGraph4.addEdge(*edge6, 5, 6, 5);

        std::cout << "G1 == G2 -> ";
        std::cout << ((dGraph1 == dGraph2) ? "True" : "False") << std::endl;

        std::cout << "============================" << std::endl;

        std::cout << "Operator '='" << std::endl;

        dGraph2.clean();
        std::cout << std::endl;

        std::cout << "Contents of Graph2: ";
        std::cout << std::endl;
        std::cout << dGraph2;

        std::cout << std::endl;

        std::cout << "Assigning graph1 to graph2: ";
        std::cout << std::endl;
        dGraph2 = dGraph1;
        std::cout << "Contents of Graph2 After Assignments: " << std::endl;
        std::cout << dGraph2;

        std::cout << std::endl << std::endl;

        std::cout << "============================" << std::endl;

        std::cout << "Operator '<<' " << std::endl;

        std::cout << dGraph2;

        std::cout << "============================" << std::endl;

        std::cout << "Operator '++' " << std::endl;
        dGraph2++;
        ++dGraph1;
        std::cout << dGraph2;
        std::cout << std::endl;
        std::cout << dGraph1;
        std::cout << "============================" << std::endl;

        std::cout << "Operator '>' , '<' " << std::endl;
        dGraph1++;
        std::cout << "Graph1 > Graph2 -> ";
        std::cout << ((dGraph1 > dGraph2) ? "True" : "False") << std::endl;

        std::cout << "Graph1 < Graph2 -> ";
        std::cout << ((dGraph1 < dGraph2) ? "True" : "False") << std::endl;

        std::cout << "============================" << std::endl;

        std::cout << "Operator '+' " << std::endl;

        std::cout << "Graph1: " << std::endl;
        std::cout << dGraph1;

        std::cout << "Graph4: " << std::endl;
        std::cout << dGraph4;

        std::cout << std::endl;
        std::cout << "Graph3 = Graph1 + Graph3 " << std::endl;
        dGraph3 = (dGraph1 + dGraph4);
        std::cout << dGraph3;

        std::cout << "============================" << std::endl;


        delete edge1, edge2, edge3, edge4;

    } else if (type == 2) {
        UndirectedGraph dGraph1;
        UndirectedGraph dGraph2;
        UndirectedGraph dGraph3;
        UndirectedGraph dGraph4;

        std::cout << "Overloaded Operator Tests:" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "Operator '==' " << std::endl;

        // Set up graph 1
        dGraph1.addVertex(std::make_shared<Vertex>(1, 3));
        dGraph1.addVertex(std::make_shared<Vertex>(2, 4));
        dGraph1.addVertex(std::make_shared<Vertex>(3, 5));

        auto *edge1 = new Edge;
        auto *edge2 = new Edge;
        dGraph1.addEdge(*edge1, 1, 3, 2);
        dGraph1.addEdge(*edge2, 2, 3, 5);

        // Set up Graph 2
        dGraph2.addVertex(std::make_shared<Vertex>(1, 3));
        dGraph2.addVertex(std::make_shared<Vertex>(2, 4));
        dGraph2.addVertex(std::make_shared<Vertex>(3, 5));

        auto *edge3 = new Edge;
        auto *edge4 = new Edge;
        dGraph2.addEdge(*edge3, 1, 3, 2);
        dGraph2.addEdge(*edge4, 2, 3, 5);

        // Set up Graph 4
        dGraph4.addVertex(std::make_shared<Vertex>(4, 6));
        dGraph4.addVertex(std::make_shared<Vertex>(5, 7));
        dGraph4.addVertex(std::make_shared<Vertex>(6, 8));

        auto *edge5 = new Edge;
        auto *edge6 = new Edge;
        dGraph4.addEdge(*edge5, 4, 5, 2);
        dGraph4.addEdge(*edge6, 5, 6, 5);

        std::cout << "G1 == G2 -> ";
        std::cout << ((dGraph1 == dGraph2) ? "True" : "False") << std::endl;

        //dGraph1.clean();
        dGraph2.clean();
        std::cout << std::endl;

        std::cout << "Contents of Graph2: ";
        std::cout << std::endl;
        std::cout << dGraph2;

        std::cout << std::endl;

        std::cout << "Assigning graph1 to graph2: ";
        std::cout << std::endl;
        dGraph2 = dGraph1;
        std::cout << "Contents of Graph2 After Assignments: " << std::endl;
        std::cout << dGraph2;

        std::cout << std::endl << std::endl;

        std::cout << "============================" << std::endl;

        std::cout << "Operator '<<' " << std::endl;

        std::cout << dGraph2;

        std::cout << "============================" << std::endl;

        std::cout << "Operator '++' " << std::endl;
        dGraph2++;
        ++dGraph1;
        std::cout << dGraph2;
        std::cout << std::endl;
        std::cout << dGraph1;
        std::cout << "============================" << std::endl;

        std::cout << "Operator '>' , '<' " << std::endl;
        dGraph1++;
        std::cout << "Graph1 > Graph2 -> ";
        std::cout << ((dGraph1 > dGraph2) ? "True" : "False") << std::endl;

        std::cout << "Graph1 < Graph2 -> ";
        std::cout << ((dGraph1 < dGraph2) ? "True" : "False") << std::endl;

        std::cout << "============================" << std::endl;

        std::cout << "Operator '+' " << std::endl;

        std::cout << "Graph1: " << std::endl;
        std::cout << dGraph1;

        std::cout << "Graph4: " << std::endl;
        std::cout << dGraph4;

        std::cout << std::endl;
        std::cout << "Graph3 = Graph1 + Graph3 " << std::endl;
        dGraph3 = (dGraph1 + dGraph4);
        std::cout << dGraph3;

        std::cout << "============================" << std::endl;


        delete edge1, edge2, edge3, edge4;
    } else if (type == 3) {
        AcyclicGraph dGraph1;
        AcyclicGraph dGraph2;
        AcyclicGraph dGraph3;
        AcyclicGraph dGraph4;

        std::cout << "Overloaded Operator Tests:" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "Operator '==' " << std::endl;



        // Set up graph 1
        dGraph1.addVertex(std::make_shared<Vertex>(1, 3));
        dGraph1.addVertex(std::make_shared<Vertex>(2, 4));
        dGraph1.addVertex(std::make_shared<Vertex>(3, 5));

        auto *edge1 = new Edge;
        auto *edge2 = new Edge;
        dGraph1.addEdge(*edge1, 1, 3, 2);
        dGraph1.addEdge(*edge2, 2, 3, 5);

        // Set up Graph 2
        dGraph2.addVertex(std::make_shared<Vertex>(1, 3));
        dGraph2.addVertex(std::make_shared<Vertex>(2, 4));
        dGraph2.addVertex(std::make_shared<Vertex>(3, 5));

        auto *edge3 = new Edge;
        auto *edge4 = new Edge;
        dGraph2.addEdge(*edge3, 1, 3, 2);
        dGraph2.addEdge(*edge4, 2, 3, 5);

        // Set up Graph 4
        dGraph4.addVertex(std::make_shared<Vertex>(4, 6));
        dGraph4.addVertex(std::make_shared<Vertex>(5, 7));
        dGraph4.addVertex(std::make_shared<Vertex>(6, 8));

        auto *edge5 = new Edge;
        auto *edge6 = new Edge;
        dGraph4.addEdge(*edge5, 4, 5, 2);
        dGraph4.addEdge(*edge6, 5, 6, 5);

        std::cout << "G1 == G2 -> ";
        std::cout << ((dGraph1 == dGraph2) ? "True" : "False") << std::endl;

        //dGraph1.clean();
        dGraph2.clean();
        std::cout << std::endl;

        std::cout << "Contents of Graph2: ";
        std::cout << std::endl;
        std::cout << dGraph2;

        std::cout << std::endl;

        std::cout << "Assigning graph1 to graph2: ";
        std::cout << std::endl;
        dGraph2 = dGraph1;
        std::cout << "Contents of Graph2 After Assignments: " << std::endl;
        std::cout << dGraph2;

        std::cout << std::endl << std::endl;

        std::cout << "============================" << std::endl;

        std::cout << "Operator '<<' " << std::endl;

        std::cout << dGraph2;

        std::cout << "============================" << std::endl;

        std::cout << "Operator '++' " << std::endl;
        dGraph2++;
        ++dGraph1;
        std::cout << dGraph2;
        std::cout << std::endl;
        std::cout << dGraph1;
        std::cout << "============================" << std::endl;

        std::cout << "Operator '>' , '<' " << std::endl;
        dGraph1++;
        std::cout << "Graph1 > Graph2 -> ";
        std::cout << ((dGraph1 > dGraph2) ? "True" : "False") << std::endl;

        std::cout << "Graph1 < Graph2 -> ";
        std::cout << ((dGraph1 < dGraph2) ? "True" : "False") << std::endl;

        std::cout << "============================" << std::endl;

        std::cout << "Operator '+' " << std::endl;

        std::cout << "Graph1: " << std::endl;
        std::cout << dGraph1;

        std::cout << "Graph4: " << std::endl;
        std::cout << dGraph4;

        std::cout << std::endl;
        std::cout << "Graph3 = Graph1 + Graph3 " << std::endl;
        dGraph3 = (dGraph1 + dGraph4);
        std::cout << dGraph3;

        std::cout << "============================" << std::endl;


        delete edge1, edge2, edge3, edge4;
    }
*/
}

int main() {
    bool isRunning = true;
    Graph *graph;
    int graphChoice;
    bool isDirected = false, isUndirected = false, isAcyclic = false;

    std::cout << "What kind of graph would you like to make? " << std::endl;
    do{
        std::cout << std::endl;
        std::cout << "1 - Directed Graph" << std::endl;
        std::cout << "2 - Directed Acyclic Graph" << std::endl;
        std::cout << "3 - Undirected Graph" << std::endl;
        std::cin >> graphChoice;
    }while(graphChoice > 3 or graphChoice < 1);

    switch(graphChoice){
        case 1:
            graph = new DirectGraph();
            isDirected = true;
            break;
        case 2:
            graph = new AcyclicGraph();
            isAcyclic = true;
            break;
        case 3:
            graph = new UndirectedGraph();
            isUndirected = true;
            break;

        default:
            exit(1);
    }

    // Menu

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
                  << "h ------ toString" << std::endl
                  << "i ------ clean" << std::endl
                  << "j ------ Test Operators" << std::endl
                  << "k ------ AddVertexArray (Bonus)" << std::endl
                  << "l ------ AddEdgeArray (Bonus)" << std::endl
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
            auto *e = new Edge();
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

        if(__choice == 'h'){
            std::cout << (graph->toString() ? "" : "\nNo nodes in graph") << std::endl;
            std::cout << std::endl;
        }

        if(__choice == 'i'){
            std::cout << (graph->clean() ? "Success" : "Failed") << std::endl;
        }

        if(__choice == 'j') {
            int type;
            if(isDirected){
                type = 1;
            } else if (isUndirected) {
                type = 2;
            } else if (isAcyclic) {
                type = 3;
            }
            OperatorTest(type);
        }

        if(__choice == 'k'){
            int _arrayChoice;
            while(_arrayChoice != -1){
                std::cout << "\nEnter Vertex Data, to exit, enter -1: " << std::endl;
                std::cin >> _arrayChoice;

                if(_arrayChoice != -1){
                    auto ptr = std::make_shared<Vertex>(_arrayChoice);
                    std::cout << (graph->addVertex(ptr) ? "Success" : "Failed") << std::endl;
                }
            }
        }

        if(__choice == 'l'){
            int _src, _dest, _weight;
            char _exit;
            while(_exit != 'n' || _exit != 'N'){
                std::cout << "Would you like to add another edge? (y/n) ";
                std::cin >> _exit;

                if(_exit == 'n' || _exit == 'N') {
                    break;
                } else {
                    std::cout << "To exit ,enter -1 for any field: " << std::endl;
                    std::cout << "\nEnter Edge Source: ";
                    std::cin >> _src;
                    std::cout << "\nEnter Edge Destination: ";
                    std::cin >> _dest;
                    std::cout << "\nEnter Edge Weight: ";
                    std::cin >> _weight;

                    auto *edge = new Edge;

                    std::cout << (graph->addEdge(*edge, _src, _dest, _weight) ? "Success" : "Failed") << std::endl;
                }
            }
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