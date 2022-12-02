#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;


bool prob_true(double p){
    return rand()%100 < p;
}

int main(){
    srand(2);

    //put probability from 1-100
    int prob = 20;
    int n = 100;

    // for(int i=1; i<101; i++){
    //     cout<<prob_true((i));
    // }

    ofstream ofile;
    string outputfile = "graph_"+to_string(n)+".txt";
    ofile.open(outputfile);

    ofile<<n<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(prob_true(prob)){
                ofile<<i<<" "<<j<<endl;
            }
        }
    }
}