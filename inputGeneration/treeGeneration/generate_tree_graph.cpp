#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    int n = 10000;

    ofstream ofile;
    string outputfile = "tree_graph_"+to_string(n)+".txt";
    ofile.open(outputfile);

    ofile<<n<<endl;
    for(int i=0; i<n; i++){
        if(((2*i)+1) < n){
            ofile<<i<<" "<<(2*i)+1<<endl;
            ofile<<i<<" "<<2*(i+1)<<endl;
        }
    }
}