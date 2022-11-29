#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

ofstream myfile; //allows to write to the output file
Graph graph;

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
    while (getline(fileObj, line))
    {
        string edgeS = "";
        string edgeD = "";
        stringstream ss(line);
        getline(ss, edgeS, ' ');
        getline(ss, edgeD, ' ');
        if (edgeD==""){
            graph = Graph(stoi(edgeS));
        }
        else{
            graph.addEdge(stoi(edgeS),stoi(edgeD));
        }
    }
}

int main(int argc, char *argv[])
{

    /*Graph graph = Graph(5);
    graph.addEdge(0, 3);
    graph.addEdge(0, 2);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 4);
    graph.printGraph();
    cout << "\ndfs\n";
    graph.DFS(0);
    graph.BFS(0); */

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
    graph.DFS(0);
    graph.BFS(0);
}