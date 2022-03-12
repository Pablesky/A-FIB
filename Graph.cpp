#include "Graph.h"

Graph::Graph() {
}

Graph::Graph(int n) {
    this->graph = vector<vector<int> >(n);
    this->visited = vector<bool>(n, false);
    this->n = n;
    this->connected_components = 0;
}

Graph::~Graph(){
}

int Graph::num_vertices() {
    return n;
}

int Graph::num_edges() {
    return m;
}

int Graph::num_cc() {
    return connected_components;
}

void Graph::get_connected_components() {
    this->visited = vector<bool>(this->n, false);

    for (int v = 0; v < this->n; ++v) {
        if (not this->visited[v]) {

            vector<bool> visited_in_dfs(this->n, false);
            dfs_util(v, visited_in_dfs);

            vector<pair<bool,vector<int> > > CC_graph(n);

            for (int i = 0; i < this->n; ++i) {
                if (visited_in_dfs[i]) {
                    CC_graph[i] = {true, this->graph[i]};
                }
                else {
                    CC_graph[i] = {false, vector<int>()};
                }
            }

            CC_graphs.push_back(CC_graph);
            ++connected_components;
        }
    }
}

void Graph::read() {
    int edges;
    cout << "NUMBER OF EDGES: ?" << endl;
    cin >> edges;
    this->m = edges;

    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;

        add_edge(v,u);
        add_edge(u,v);
    }

    cout << "GRAPH READ CORRECTLY" << endl;
}

void Graph::add_edge(int v, int u) {
    this->graph[v].push_back(u);
}

void Graph::write() {
    cout << "ORIGINAL GRAPH: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "VERTEX " << i << ": ";
        for (int j = 0; j < this->graph[i].size(); ++j) {
            cout << this->graph[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::write_CCs() {

    for (int i = 0; i < this->connected_components; ++i) {
        cout << "CC NUMBER: " << i << " " << endl;

        for (int j = 0; j < this->n; ++j) {
            if (this->CC_graphs[i][j].first) {
                cout << "NODE: " << j << " EDGES: ";
                for (int k = 0; k < this->CC_graphs[i][j].second.size(); ++k) {
                    cout << this->CC_graphs[i][j].second[k] << ' ';
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::get_complex_ccs() {
    for (int i = 0; i < this->connected_components; ++i) {
        if (is_unicyclic(this->CC_graphs[i]) or is_tree(this->CC_graphs[i])) this->complex_cc.push_back(true);
        else this->complex_cc.push_back(false);
    }
}

bool Graph::is_complex(int cc) {
    return this->complex_cc[cc];
}

void Graph::dfs_util(int v, vector<bool>& visited_dfs) {
    this->visited[v] = true;
    visited_dfs[v] = true;

    for (int u : this->graph[v]) {
        if (not this->visited[u]) {
            dfs_util(u, visited_dfs);
        }
    }
}

// O(V + E)
bool Graph::is_tree(const vector<pair<bool,vector<int> >>& CC_graph) {
    vector<bool> visited_tree(this->n, false);

    int root = 0;

    for (int i = 0; i < this->n; ++i) {
        if (CC_graph[i].first) {root = i; break;}
    }

    // cout << "ROOT: " << root << endl;
    // check if each node has exactly one parent (except for the root)
    if (not dfs_is_tree(root,-1,visited_tree, CC_graph)) return false;
    // check if is connex (needed?)
    for (int v = 0; v < this->n; ++v) {
        if (CC_graph[v].first and not visited_tree[v]) return false;
    }

    return true;
}

// O(V + E)
bool Graph::dfs_is_tree(int v, int parent, vector<bool>& visited_tree, const vector<pair<bool,vector<int> >>& CC_graph) {
    if (visited_tree[v]) return false;

    visited_tree[v] = true;

    if (CC_graph[v].first) {
        //cout << "NODE: " << v << endl;
        for (int u : CC_graph[v].second) {
            if (u != parent) {
                /*cout << "CHILD ?" << endl;
                cout << u << endl;*/
                bool res = dfs_is_tree(u, v, visited_tree, CC_graph);
                if (not res) return false;
            }
        }
    }
    return true;
}

void Graph::DFSCycle(const vector<pair<bool,vector<int> >>& CC_graph, int u, int p, vector<int>& color,
                     vector<int>& par, int& cyclenumber){

    //the node is already considered
    if (color[u] == 2) return;

    //partially visited node found i.e new cycle found
    if (color[u] == 1) {++cyclenumber; return;}

    //storing parent of u
    par[u] = p;

    //marking as partially visited
    color[u] = 1;

    for (int v: CC_graph[u].second) {
        if (v == par[u]) continue;
        DFSCycle(CC_graph, v, u, color, par, cyclenumber);
    }

    //marking as fully visited
    color[u] = 2;
}

bool Graph::is_unicyclic(const vector<pair<bool,vector<int> >>& CC_graph) {
    int root = 0;

    for (int i = 0; i < this->n; ++i) {
        if (CC_graph[i].first) {root = i; break;}
    }

    vector<int> color(this->n);
    vector<int> par(this->n);
    int cycle_n = 0;
    this->DFSCycle(CC_graph,root,-1,color,par,cycle_n);

    return cycle_n == 1;
}
