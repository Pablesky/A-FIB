#include <iostream>
#include <map>
#include <math.h>
using namespace std;

// Pre: G is a non-void graph and p is between 0 and 1
Graph binomial_random_graph(Graph& G, float p) {
    int n = G.number_nodeS();       // Obtains the number of nodes
    Graph G2 = Graph(n);            // Creates a graph with n nodes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // For each edge obtain a random number between 0 and 1
            // if this random number is lower o equal than the
            // probability setted then the edge is added to 
            // the new graph
            if (G[i][j]) {
                float r = (float) rand() / RAND_MAX;
                if (r <= p)
                    G2.add_edge(i, j);
                    G2.add_edge(j, i);
            }
        }
    }
}

// Pre: G is a non-void graph and r is between 0 and 1
Graph random_geometric_graph(Graph& G, float r) {
    int n = G.number_nodeS();       // Obtains the number of nodes
    map<int, pair<float, float> > data;
    Graph G2 = Graph(n);            // Creates a graph with n nodes
    for (int i = 0; i < n; i++) {
        float x = (float) rand() / RAND_MAX;
        float y = (float) rand() / RAND_MAX;    // Gets a random position

        for (map<int, pair<float, float> >::iterator it = data.begin(); it != data.end(); it++) {
            float val1 = it->second.first - x;
            float val2 = it->second.second - y;
            float dist = sqrt(val1 * val1 + val2 * val2);   // Calculates the Euclidean distance

            if (dist <= r)
                G2.add_edge(i, it->first);
                G2.add_edge(it->first, i);
        }

        data.insert(pair<int, pair<float, float> > (i, pair<float, float>(x, y)));
    }
}