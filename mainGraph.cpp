#include "Graph.h"
#include "percolacion.hh"
using namespace std;

/*
int main() {

    int n;
    cin >> n;

    Graph G(n);
    G.read();
    G.get_connected_components();
    cout << G.num_cc() << endl;
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
    cout << "Introduce numero arestas" << endl;
    cin >> n;

    Graph G(n);
    G.read();
    G.write();

    Graph newGraf = percolationVertex(G, 0.5);
    newGraf.write();
}
