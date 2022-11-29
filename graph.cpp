#include <iostream>
#include <stdlib.h>
using namespace std;

#include "graph.h"


Graph::Graph(int v) {
    numVertices = v;
    adjLists = new list<int>[v];
    visited = new bool[v];
}

Graph::Graph(){
    numVertices = 0;
    adjLists = new list<int>[0];
    visited = new bool[0];
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::printGraph() {
    for (int i = 0; i < numVertices; i++) {
        cout << "Node " << i << ": ";
        for (auto j : adjLists[i]) {
            cout << j << " "; 
        }
        cout << "\n";
    }
}

void Graph::DFS(int v) {
    visited[v] = true;
    list<int> adjList = adjLists[v];
    cout << "Node " << v << ": ";
    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); i++) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }
}

void Graph::BFS(int v){
    cout<<"bfs"<<endl;
    for(int i=0; i<numVertices; i++)visited[i] = false;

    list<int> queue;
    
    visited[v] = true;
    queue.push_back(v);

    while(!queue.empty()){
        v = queue.front();
        cout<<v<<" ";
        queue.pop_front();

        for(int adj: adjLists[v]){
            if(!visited[adj]){
                visited[adj] = true;
                queue.push_back(adj);
            }
        }
    }
    cout<<endl;
}
