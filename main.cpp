#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "graphmatrix.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

ofstream myfile; //allows to write to the output file
Graph graph;
GraphMatrix matrixgraph;

bool fileOpen(string file, ifstream &fileObj) //opens the desired file
{
    fileObj.open(file);
    if (fileObj.is_open())
    {
        return true;
    }
    else
    {
        cout << "does not open" << endl;
        return false;
    }
}

void readFile(string file, ifstream &fileObj, string output) //reads in the input file and runs given commands
{
    string line;
    int globalStart;
    int globalEnd;
    string alg;
    while (getline(fileObj, line))
    {
        string edgeS = "";
        string edgeD = "";
        alg = "";
        stringstream ss(line);
        getline(ss, edgeS, ' ');
        getline(ss, edgeD, ' ');
        getline(ss, alg, ' ');
        if (edgeD==""){
            graph = Graph(stoi(edgeS));
            matrixgraph = GraphMatrix(stoi(edgeS));
        }
        else if (alg != "") {
            globalStart = stoi(edgeS);
            globalEnd = stoi(edgeD);
        }
        else{
            graph.addEdge(stoi(edgeS),stoi(edgeD));
            matrixgraph.addEdge(stoi(edgeS),stoi(edgeD));
        }
    }
    cout << "Start node" << globalStart << ", End node " << globalEnd << "\n \n";
    cout << "Adjacency List:\n";
    cout<<"BFS:\n";
    graph.callBFS(globalStart, globalEnd);
    cout<<"DFS\n";
    graph.callDFS(globalStart, globalEnd);
    cout << "Adjacency Matrix:\n";
    cout << "DFS:\n";
    matrixgraph.callDFS(globalStart, globalEnd);
    cout << "BFS:\n";
    matrixgraph.callBFS(globalStart, globalEnd);

}

int main(int argc, char *argv[])
{

    //GraphMatrix matrixgraph = GraphMatrix(10);
    
    //  doesnt work
    /*
    matrixgraph.addEdge(0, 3);
    matrixgraph.addEdge(0, 2);
    matrixgraph.addEdge(0, 1);
    matrixgraph.addEdge(1, 2);
    matrixgraph.addEdge(2, 4);
    */
    //  works
    /*
    matrixgraph.addEdge(0, 5);
    matrixgraph.addEdge(0, 1);
    matrixgraph.addEdge(0, 2);
    matrixgraph.addEdge(5, 4);
    matrixgraph.addEdge(4, 12);
    matrixgraph.addEdge(2, 7);
    matrixgraph.addEdge(1, 3);
    matrixgraph.addEdge(6, 3);
    matrixgraph.addEdge(7, 9);
    matrixgraph.addEdge(3, 9);
    matrixgraph.addEdge(7, 8);
    matrixgraph.addEdge(16, 7);
    matrixgraph.addEdge(8, 15);
    matrixgraph.addEdge(17, 15);
    matrixgraph.addEdge(17, 14);
    matrixgraph.addEdge(17, 18);
    matrixgraph.addEdge(6, 11);
    matrixgraph.addEdge(11, 13);
    matrixgraph.addEdge(10, 6);
    matrixgraph.addEdge(10, 19);
    matrixgraph.addEdge(19, 20);
    matrixgraph.addEdge(21, 20);
    matrixgraph.addEdge(10, 21);
    */
    //matrixgraph.printGraph();
    //matrixgraph.callDFS(0, 6);
    //graph.DFS(0);
    //graph.BFS(0);
    
    ifstream fin;
    char commands;
    string input = "default";
    string output = "default";
    input = argv[1]; //gets input file namecl
    output = argv[2]; //gets output file name
    freopen(output.c_str(),"w",stdout);
    if (fileOpen(input, fin)) //opens input file
    {
        readFile(input, fin, output); //reads in input file
        fin.close(); //closes input file
    }
    
}