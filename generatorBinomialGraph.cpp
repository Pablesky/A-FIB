#include "Graph.h"
#include "percolacion.hh"
#include "binomial.hh"
#include <fstream>
using namespace std;

void Usage() {
    cout << "U need to specify the number of nodes, the probability of edges appear, and the name of the file u want to save." << endl;
}

int main(int argc, char** argv) {
    if (argc != 4) Usage();
    else {
        ofstream myfile (string(argv[3]) + ".txt");

        int n = atoi(argv[1]);
        float prob = atof(argv[2]);
        Graph g = binomial_random_graph(n, prob);
        g.writeOutput(myfile);
    }
}
