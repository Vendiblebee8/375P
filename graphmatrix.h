#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

//  Graph Class - Implementation of graph data structure with built in algorithms

class GraphMatrix {
    public:
        GraphMatrix();
        GraphMatrix(int v);
        void addEdge(int x, int y);
        void printGraph();
        void callDFS(int start, int end);
        void DFS(int v);
        void printDFS();
        void BFS(int v);
        void callBFS(int start, int end);

    private:
        int numVertices;
        int *nodeNames;
        bool **matrix;
        bool *visited;
        int *previousNodes;
        int startVertex = 0;
        int endVertex = 0;
        int curLength = 0;
        int curBestLength = INT_MAX;
};

#endif
