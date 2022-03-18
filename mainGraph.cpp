#include "Graph.h"
#include "percolacion.hh"
#include "binomial.hh"
using namespace std;

/*int main() {
    int n;
    cin >> n;
    Graph G(n);
    G.read();
    G.write();
    G = percolationAresta(G,0);
    G.write();
    cout << endl;
    G.get_connected_components();
    G.write_CCs();
    G.get_complex_ccs();
    cout << "NUMBER OF CCS: " << G.num_cc() << endl;
    cout << endl;
    for (int i = 0; i < G.num_cc(); ++i) {
        if (G.is_complex(i)) cout << "CC : " << i << " is complex" << endl;
        else cout << "CC : " << i << " is NOT complex" << endl;
    }
}*/

int main() {
    int n;
    cin >> n;

    Graph g(n);

    cout << "reading" << endl;
    g.readOutput();
    //g.write();

    /*cout << "Vacio vertices" << endl;
    Graph g2 = percolationVertex(g, 0.0);
    //g2.write();

    cout << "Lleno vertices" << endl;
    g2 = percolationVertex(g, 1.0);
    //g2.write();

    cout << "Mitad vertices" << endl;
    g2 = percolationVertex(g, 0.5);
    //g2.write();

    cout << "Vacio aristas (el mas tocho)" << endl;
    g2 = percolationAresta(g, 0.0);
    //g2.write();

    cout << "Lleno aristas" << endl;
    g2 = percolationAresta(g, 1.0);
    //g2.write();*/

    cout << "Mitad aristas" << endl;
    Graph g2 = percolationAresta(g, 0.0005);
    //g2.write();

    g2.get_connected_components();
    g2.write_CCs();
    cout << "NUMBER OF CCS: " << g2.num_cc() << endl;
}
