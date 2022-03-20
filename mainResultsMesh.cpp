#include <iostream>
#include "Graph.h"
#include "binomial.hh"
#include "percolacion.hh"

using namespace std;

int main() {
    Graph g = mesh_graph(4);
    g.write();
}