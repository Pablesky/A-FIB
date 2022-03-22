#include <iostream>
#include "Graph.h"
#include "binomial.hh"
#include "percolacion.hh"

using namespace std;

int main() {
    srand(SEED);
    
    int NODOS, N_GRAFOS, PROBABILIDADES;
    float ESCALADO;

    cout << "Introduce numero de nodos: " << endl;
    cin >> NODOS;

    cout << "Introduce la probabilidad cada cuanto quieres obtener los datos (realizar percolacion por arestas): " << endl;
    cin >> ESCALADO;

    cout << "Numero de grafos por recoleccion de datos: " << endl;
    cin >>  N_GRAFOS;

    PROBABILIDADES = int(1.0/ESCALADO) + 1;

    cout << "Empiezo a calcular" << endl;

    for (int i = 0; i < PROBABILIDADES; ++i) {
        cout << (i * ESCALADO) << ',';
    }

    cout << endl;

    vector<float> conectividad(PROBABILIDADES, 0);
    vector<float> complejidad(PROBABILIDADES, 0);

    Graph g = mesh_graph(NODOS), percolated;
    int conexo, noConexo, complejas, noComplejas;
    float prob;
    for (int i = 0; i < PROBABILIDADES; ++i) {
        prob = i * ESCALADO;
        conexo = 0;
        noConexo = 0;
        complejas = 0;
        noComplejas = 0;
        for (int j = 0; j < N_GRAFOS; ++j) {
            percolated = percolationAresta(g, prob);
            percolated.get_connected_components();
            if (percolated.num_cc() == 1) ++conexo;
            else ++noConexo;
            
            if (percolated.num_cc() == percolated.getNumberComplex()) ++complejas;
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