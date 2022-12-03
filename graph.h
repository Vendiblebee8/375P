#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <chrono>
#include <string>
#include <queue>
using namespace std::chrono;
using namespace std;

//  Graph Class - Implementation of graph data structure with built in algorithms

class Graph {
    public:
        Graph();
        Graph(int v);
        void addEdge(int src, int dest);
        void printGraph();
        bool BFS(int src, int dest, int parent[]);
        void get_BFS_path(int src, int dest); 
        // bool DFS(int src, int dest, int parent[]);
        // void get_DFS_path(int src, int dest); 
        void DFS(int v, int dest);
        // void BFS(int v);
        void callDFS(int start, int end);
        void callBFS(int start, int end);

    private:
        int numVertices;
        vector<int> *adjList;
        vector<bool> vis;
        bool found = false;
};

#endif
