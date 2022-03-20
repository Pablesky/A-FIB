#include <iostream>
#include "Graph.h"
#include "binomial.hh"
#include "percolacion.hh"

using namespace std;

int main() {
    srand(SEED);
    
    int NODOS, N_GRAFOS, PROBABILIDADES;
    float ESCALADO;

    cout << "Introduce nodos: " << endl;
    cin >> NODOS;

    cout << "Introduce probabilidad binomial/geometric: " << endl;
    cin >> ESCALADO;

    cout << "Numero de grafos por probabilidad: " << endl;
    cin >>  N_GRAFOS;

    PROBABILIDADES = int(1.0/ESCALADO) + 1;

    cout << "Empiezo a calcular" << endl;

    for (int i = 0; i < PROBABILIDADES; ++i) {
        cout << (i * ESCALADO) << ',';
    }

    cout << endl;

    Graph g;
    int conexo, noConexo;
    float prob;
    for (int i = 0; i < PROBABILIDADES; ++i) {
        prob = i * ESCALADO;
        conexo = 0;
        noConexo = 0;
        for (int j = 0; j < N_GRAFOS; ++j) {
            g = binomial_random_graph(NODOS, prob);
            g.get_connected_components();
            if (g.num_cc() == 1) ++conexo;
            else ++noConexo;
        }

        cout << float(conexo)/float(noConexo + conexo) << ',';
    }

    cout << endl;
}