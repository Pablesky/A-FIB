#include "percolacion.hh"
#include <random>

Graph percolationVertex(Graph& grafo, const double probabilidad) {
    Graph newGraph = Graph(grafo);

    int numVertices = grafo.num_vertices();
    double random;
    for (int i = 0; i < numVertices; ++i) {
        random = (double)rand() / (double)RAND_MAX;
        if (random > probabilidad) {
            newGraph.delete_vertex(i);
        }
    }

    return newGraph;
}

Graph percolationAresta(Graph& grafo, const double probabilidad) {
    Graph newGraph = Graph(grafo);
    int numVertices = grafo.num_vertices();

    double random;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            if (grafo.exist_edge(i, j)) {
                random = (double)rand() / (double)RAND_MAX;
                if (random > probabilidad) {
                    newGraph.delete_edge(i, j);
                }
            }
        }
    }
    return newGraph;
}