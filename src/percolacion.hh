#include "Graph.h"

/**
 * @brief Dado un grafo, y una probabilidad, realiza la percolacion de los vertices con una probabilidad p.
 * 
 * @param grafo Dado el grafo a realizar la operacion.
 * @param probabilidad Un valor entre 0 y 1 el cual indica la probabilidad de que ese vertice se mantenga.
 * @return Grafo despues de haber aplicado la percolacion de los vertices.
 */
Graph percolationVertex(Graph& grafo, const double probabilidad);

/**
 * @brief Dado un grafo, y una probabilidad, realiza la percolacion de las aristas con una probabilidad p.
 * 
 * @param grafo Dado el grafo a realizar la operacion.
 * @param probabilidad Un valor entre 0 y 1 el cual indica la probabilidad de que ese vertice se mantenga.
 * @return Grafo despues de haber aplicado la percolacion de las aristas.
 */
Graph percolationAresta(Graph& grafo, const double probabilidad);