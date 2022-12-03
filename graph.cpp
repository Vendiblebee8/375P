#include <iostream>
#include <stdlib.h>
using namespace std;

#include "graph.h"

Graph::Graph(int v) {
    numVertices = v;
    adjList = new vector<int> [v];
    for(int i=0; i<numVertices; i++){
        vis.push_back(false);
    }
}

Graph::Graph(){
    numVertices = 0;
}

void Graph::addEdge(int src, int dest) {
    bool insrc = false;
    for(int i: adjList[src]){
        if(i == dest) insrc = true;
    }
    bool indest = false;
    for(int i: adjList[dest]){
        if(i == src) indest = true;
    }
    if(!insrc) adjList[src].push_back(dest);
    if(!indest) adjList[dest].push_back(src);
}

void Graph::printGraph() {
    for (int i = 0; i < numVertices; i++) {
        cout << "Node " << i << ": ";
        for (auto j : adjList[i]) {
            cout << j << " "; 
        }
        cout << "\n";
    }
}

bool Graph::BFS(int src, int dest, int parent[]){
    queue<int> q;
    bool visited[numVertices];

    for(int i=0; i<numVertices; i++){
        visited[i] = false;
        parent[i] = -1;
    }

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i: adjList[curr]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = curr;

                if(i == dest){
                    return true;
                }
            }
        }
    }
    return false;
}
void Graph::get_BFS_path(int src, int dest){
    int parent[numVertices];
    if(!BFS(src, dest, parent)){
        cout<<dest<<" not reachable from "<<src<<endl;
        return;
    }

    vector<int> path;

    while(parent[dest] != -1){
        path.push_back(dest);
        dest = parent[dest];
    }

    cout<<src;
    while(!path.empty()){
        string curr = to_string(path[path.size()-1]);
        cout<<" -> "<<curr;
        path.pop_back();
    }
    return;
}

void Graph::DFS(int src, int dest) {
    if(src == dest) {
        found = true;
        cout<<src;
        return;
    }

    vis[src] = true;

    cout << src << " -> ";
    for (int i: adjList[src]) {
        if (!vis[i] && !found) {
            DFS(i,dest);
        }
    }
}

// void Graph::BFS(int v){
//     cout<<"bfs"<<endl;
//     for(int i=0; i<numVertices; i++)visited[i] = false;

//     list<int> queue;
    
//     visited[v] = true;
//     queue.push_back(v);

//     while(!queue.empty()){
//         v = queue.front();
//         cout<<v<<" ";
//         queue.pop_front();

//         for(int adj: adjList[v]){
//             if(!visited[adj]){
//                 visited[adj] = true;
//                 queue.push_back(adj);
//             }
//         }
//     }
//     cout<<endl;
// }

void Graph::callDFS(int start, int end) {
    auto chronoStart = high_resolution_clock::now();
    DFS(start,end);     //  actually call the algorithm
    auto chronoStop = high_resolution_clock::now();
    duration<double> diff = (chronoStop - chronoStart);
    cout << "DFS Runtime: " << diff.count() * 1000 << " seconds" << "\n";
}

void Graph::callBFS(int start, int end) {
    auto chronoStart = high_resolution_clock::now();
    get_BFS_path(start, end);     //  actually call the algorithm
    auto chronoStop = high_resolution_clock::now();
    duration<double> diff = (chronoStop - chronoStart);
    cout << "DFS Runtime: " << diff.count() * 1000 << " seconds" << "\n";
}