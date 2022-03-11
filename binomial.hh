#include <iostream>
#include <map>
#include <math.h>

/**
 * @brief Dado un grafo, y una probabilidad, devuelve un grafo con el numero de aristas igual o menor al original en función de p.
 * 
 * @param grafo Dado el grafo a realizar la operacion.
 * @param probabilidad Un valor entre 0 y 1 el cual indica la probabilidad de que ese vertice se mantenga.
 * @return Grafo despues de haber aplicado la probabilidad p a cada una de las aristas.
 */
Graph binomial_random_graph(Graph& G, float p);

/**
 * @brief Dado un grafo, y una distancia, devuelve un grafo que tendrà arista entre dos nodos si la distancia entre estos es menor o igual a r.
 * 
 * @param grafo Dado el grafo a realizar la operacion.
 * @param probabilidad Un valor entre 0 y 1 el cual indica la distancia a la que queremos que haya una arista entre dos nodos.
 * @return Grafo despues de haber aplicado el criterio de distancia entre nodos para establecer si hay arista o no.
 */
Graph random_geometric_graph(Graph& G, float r);