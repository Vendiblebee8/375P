#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <vector>
using namespace std;

//  Graph Class - Implementation of graph data structure with built in algorithms

class Graph {
    public:
        Graph();
        Graph(int v);
        void addEdge(int src, int dest);
        void printGraph();
        void DFS(int v);
        void BFS(int v);

    private:
        int numVertices;
        list<int> *adjLists;
        bool *visited;
};

#endif
