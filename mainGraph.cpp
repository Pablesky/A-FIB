#include "Graph.h"
#include "percolacion.hh"
#include "binomial.hh"
using namespace std;

/*
int main() {

    int n;
    cin >> n;

    Graph G(n);
    G.read();
    G.get_connected_components();
    cout << "THE NUM OF CCs is : " << G.num_cc() << endl;
    cout << endl;
    G.write_CCs();
    G.get_complex_ccs();
    cout << "NUMBER OF CCS: " << G.num_cc() << endl;
    cout << endl;
    for (int i = 0; i < G.num_cc(); ++i) {
        if (G.is_complex(i)) cout << "CC : " << i << " is complex" << endl;
        else cout << "CC : " << i << " is NOT complex" << endl;
    }

    cout << "------------- DELETING -------------" << endl;
    G.delete_vertex(3);
    cout << "VERTEX DELETED" << endl;
    G.get_connected_components();
    cout << " THE NUM OF CCs is : " << G.num_cc() << endl;
    cout << endl;
    G.write_CCs();
    G.get_complex_ccs();
    cout << "NUMBER OF CCS: " << G.num_cc() << endl;
    cout << endl;
    for (int i = 0; i < G.num_cc(); ++i) {
        if (G.is_complex(i)) cout << "CC : " << i << " is complex" << endl;
        else cout << "CC : " << i << " is NOT complex" << endl;
    }
}
*/

int main() {
    int n;
    cin >> n;

    Graph g(n);

    g.readOutput();
    g.write();

    cout << "Vacio" << endl;
    Graph g2 = percolationVertex(g, 0.0);
    g2.write();

    cout << "Lleno" << endl;
    g2 = percolationVertex(g, 1.0);
    g2.write();

    cout << "Mitad" << endl;
    g2 = percolationVertex(g, 0.5);
    g2.write();

    cout << "Vacio" << endl;
    g2 = percolationAresta(g, 0.0);
    g2.write();

    cout << "Lleno" << endl;
    g2 = percolationAresta(g, 1.0);
    g2.write();

    cout << "Mitad" << endl;
    g2 = percolationAresta(g, 0.5);
    g2.write();
    
}
