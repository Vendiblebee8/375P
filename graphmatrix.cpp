#include <iostream>
#include <stdlib.h>
using namespace std;

#include "graphmatrix.h"

GraphMatrix::GraphMatrix(){
    numVertices = 0;
    curLength = 0;
    curBestLength = INT_MAX;
    startVertex = 0;
    endVertex = 0;
    matrix = new bool*[0];
    visited = new bool[0];
    previousNodes = new int[0];
    nodeNames = new int[0];
}

GraphMatrix::GraphMatrix(int v) {
    numVertices = v;
    matrix = new bool*[v];
    for (int i = 0; i < v; i++) {
      matrix[i] = new bool[v];
      for (int j = 0; j < v; j++)
        matrix[i][j] = false;
    }
    previousNodes = new int[v];
    for (int i = 0; i < v; i++) {
        previousNodes[i] = -1;
    }
    visited = new bool[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    nodeNames = new int[v];
    for (int i = 0; i < v; i++) {
        nodeNames[i] = i;
    }
    distancesToSource = new int[v];
    for (int i = 0; i < v; i++) {
        distancesToSource[i] = INT_MAX;
    }

}

void GraphMatrix::addEdge(int x, int y) {
    matrix[x][y] = true;
    matrix[y][x] = true;
}

void GraphMatrix::printGraph() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void GraphMatrix::callDFS(int start, int end) {
    auto chronoStart = high_resolution_clock::now();   //  init runtime counter
    startVertex = start;
    endVertex = end;
    DFS(start);
    auto chronoStop = high_resolution_clock::now();
    duration<double> diff = (chronoStop - chronoStart);
    cout << "DFS Runtime: " << diff.count() * 1000 << " seconds" << "\n";
    printDFS();
}

void GraphMatrix::DFS(int v) {
    curLength++;
    if (curBestLength < curLength) {
        return;
    }
    if (v == endVertex) {
        curBestLength = curLength;
        return;
    }
    visited[v] = true;
    for (int i = 0; i < numVertices; i++) {
        if (matrix[v][i] && !visited[i]) {
            previousNodes[i] = v;
            DFS(i);
        }
    }
    curLength--;
}

void GraphMatrix::printDFS() {
    vector<int> result;
    int curVertex = endVertex;
    
    while (curVertex != -1) {
        result.push_back(nodeNames[curVertex]);
        curVertex = previousNodes[curVertex];
    }
    
    for (int i = result.size() - 1; i >= 0; i--) {
        if (i == 0) {
            cout << result[i];
        }
        else {
            cout << result[i] << " -> ";
        }
    }

    /*
    for (int x : result) {
        cout << x << " -> ";
    }
    */
    cout << "\n";
}

void GraphMatrix::BFS() {
    list<int> queue;
    queue.push_back(startVertex);
    visited[startVertex] = true;
    bool finished = false;
    //distancesToSource[startVertex] = 0;
    
    while (!finished && !queue.empty()) {
        int curNode = queue.front();
        queue.pop_front();
        int tempNeighbor;
        int curNeighbor;

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i] && matrix[curNode][i]) {
                tempNeighbor = i;
                break;
            }
        }

        while ((curNeighbor == tempNeighbor) && curNeighbor != -1) {
            visited[curNeighbor] = true;
            queue.push_back(curNeighbor);
            previousNodes[curNeighbor] = curNode;
            if (curNeighbor == endVertex) {
                finished = true;
                break;
            }
        }
    }
}

void GraphMatrix::printBFS() {
    vector<int> result;
    int curVertex = endVertex;
    
    while (curVertex != -1) {
        result.push_back(nodeNames[curVertex]);
        curVertex = previousNodes[curVertex];
    }
    
    for (int i = result.size() - 1; i >= 0; i--) {
        if (i == 0) {
            cout << result[i];
        }
        else {
            cout << result[i] << " -> ";
        }
    }
    cout << "\n";
}

void GraphMatrix::callBFS(int start, int end) {
    auto chronoStart = high_resolution_clock::now();
    startVertex = start;
    endVertex = end;
    BFS();
    auto chronoStop = high_resolution_clock::now();
    duration<double> diff = (chronoStop - chronoStart);
    cout << "BFS Runtime: " << diff.count() * 1000 << " seconds" << "\n";
    printBFS();
}