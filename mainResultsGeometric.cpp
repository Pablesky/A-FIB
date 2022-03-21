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

    vector<float> conectividad(PROBABILIDADES, 0);
    vector<float> complejidad(PROBABILIDADES, 0);

    Graph g;
    int conexo, noConexo, complejas, noComplejas;
    float prob;
    for (int i = 0; i < PROBABILIDADES; ++i) {
        prob = i * ESCALADO;
        conexo = 0;
        noConexo = 0;
        complejas = 0;
        noComplejas = 0;
        for (int j = 0; j < N_GRAFOS; ++j) {
            g = random_geometric_graph(NODOS, prob);
            g.get_connected_components();
            g.get_complex_ccs();
            if (g.num_cc() == 1) ++conexo;
            else ++noConexo;
            
            if (g.num_cc() == g.getNumberComplex()) ++complejas;
            else ++noComplejas;
        }

        conectividad[i] = float(conexo) / float(conexo + noConexo);
        complejidad[i] = float(complejas) /float(complejas + noComplejas);
    }

    for (int i = 0; i < PROBABILIDADES; ++i) {
        cout << conectividad[i] << ',';
    }

    cout << endl;

    for (int i = 0; i < PROBABILIDADES; ++i) {
        cout << complejidad[i] << ',';
    }

    cout << endl;
}