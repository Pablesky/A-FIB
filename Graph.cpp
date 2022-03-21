#include "Graph.h"

Graph::Graph() {
}

Graph::Graph(int n) {
    this->graph = vector<vector<int> >(n, vector<int>(n,-1));
    this->visited = vector<bool>(n, false);
    this->vertex_available = vector<bool>(n, true);
    this->n = n;
    this->degree_vertex = vector<int>(n, 0);
    this->connected_components = 0;
    this->complex_components = -1;
}

Graph::Graph(const Graph& g) {
    this->graph = g.graph;
    this->visited = g.visited;
    this->vertex_available = g.vertex_available;
    this->n = g.n;
    this->degree_vertex = g.degree_vertex;
    this->connected_components = g.connected_components;
    this->complex_components = g.complex_components;
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

void Graph::sortGraph() {
    for (int i = 0, size = this->graph.size(); i < size; ++i) {
        sort(this->graph[i].begin(), this->graph[i].end());
    }
}

// O(V^2+E)
void Graph::get_connected_components() {
    this->visited = vector<bool>(this->n, false);
    this->CC_graphs.clear();
    this->connected_components = 0;
    for (int v = 0; v < this->n; ++v) {
        int count = 0;

        if (exist_vertex(v) and not this->visited[v]) {
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
            //cout << "CONNECTED COMPONENTS SO FAR: " << this->connected_components << endl;
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
    if (exist_vertex(u) && exist_vertex(v) && !exist_edge(v, u)) {
        this->graph[v][u] = u;
        this->graph[u][v] = v;
        ++degree_vertex[u];
        ++degree_vertex[v];
    }
}

// O(V^2)
void Graph::write() {
    cout << "GRAPH of size: " << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << "VERTEX " << i << ": ";
        for (int j = 0; j < n; ++j) {
            if (exist_edge(i,j)) cout << this->graph[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::write_CCs() {
    cout << "CCS TOTAL: " << this->connected_components << endl;
    for (int i = 0; i < this->connected_components; ++i) {
        cout << "CC NUMBER: " << i << " " << endl;

        for (int j = 0; j < this->n; ++j) {
            if (this->CC_graphs[i][j].first) {
                cout << "NODE: " << j << " EDGES: ";
                for (int k = 0; k < this->CC_graphs[i][j].second.size(); ++k) {
                    if (exist_vertex(j) &&  exist_vertex(this->CC_graphs[i][j].second[k])) {

                        cout << this->CC_graphs[i][j].second[k] << ' ';
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::get_complex_ccs() {
    this->complex_cc.clear();
    complex_components = 0;
    for (int i = 0; i < this->connected_components; ++i) {
        if (is_unicyclic(this->CC_graphs[i]) or is_tree(this->CC_graphs[i])) {
            this->complex_cc.push_back(true);
            ++complex_components;
        }
        else this->complex_cc.push_back(false);
    }
}

bool Graph::is_complex(int cc) {
    return this->complex_cc[cc];
}

// O(V + E)
void Graph::dfs_util(int v, vector<bool>& visited_dfs) {
    //cout << "VISITING VERTEX: " << v << endl;
    if (exist_vertex(v)) {
        this->visited[v] = true;
        visited_dfs[v] = true;

        for (int u: this->graph[v]) {
            //cout << "VISITING EDGE: " << u << endl;
            if (exist_edge(v,u) and not this->visited[u]) {
                dfs_util(u, visited_dfs);
            }
        }
    }
}

// O(V + E)
bool Graph::is_tree(const vector<pair<bool,vector<int> >>& CC_graph) {
    vector<bool> visited_tree(this->n, false);

    int root = -1;

    for (int i = 0; i < this->n; ++i) {
        if (exist_vertex(i) and CC_graph[i].first) {root = i; break;}
    }

    if (root == -1) return false;

    // cout << "ROOT: " << root << endl;
    // check if each node has exactly one parent (except for the root)
    if (not dfs_is_tree(root,-1,visited_tree, CC_graph)) return false;
    // check if is connex (needed?)
    for (int v = 0; v < this->n; ++v) {
        if (exist_vertex(v) and CC_graph[v].first and not visited_tree[v]) return false;
    }

    return true;
}

// O(V + E)
bool Graph::dfs_is_tree(int v, int parent, vector<bool>& visited_tree, const vector<pair<bool,vector<int> >>& CC_graph) {
    if (visited_tree[v]) return false;

    visited_tree[v] = true;

    if (exist_vertex(v) and CC_graph[v].first) {
        //cout << "NODE: " << v << endl;
        for (int u : CC_graph[v].second) {
            if (exist_edge(v,u) and u != parent) {
                /*cout << "CHILD ?" << endl;
                cout << u << endl;*/
                bool res = dfs_is_tree(u, v, visited_tree, CC_graph);
                if (not res) return false;
            }
        }
    }
    return true;
}

void Graph::dfs_cycle(const vector<pair<bool,vector<int> >>& CC_graph, int u, int p, vector<int>& color,
                     vector<int>& par, int& cyclenumber){
    if (exist_vertex(u)) {
        //the node is already considered
        if (color[u] == 2) return;

        //partially visited node found i.e new cycle found
        if (color[u] == 1) {
            ++cyclenumber;
            return;
        }

        //storing parent of u
        par[u] = p;

        //marking as partially visited
        color[u] = 1;

        for (int v: CC_graph[u].second) {
            if (exist_edge(v, u)) {
                if (v == par[u]) continue;
                dfs_cycle(CC_graph, v, u, color, par, cyclenumber);
            }
        }

        //marking as fully visited
        color[u] = 2;
    }
}

bool Graph::is_unicyclic(const vector<pair<bool,vector<int> >>& CC_graph) {
    int root = -1;

    for (int i = 0; i < this->n; ++i) {
        if (exist_vertex(i) and CC_graph[i].first) {root = i; break;}
    }

    if (root == -1) return false;

    vector<int> color(this->n);
    vector<int> par(this->n);
    int cycle_n = 0;
    this->dfs_cycle(CC_graph,root,-1,color,par,cycle_n);

    //cout << "CYCLES FOUND: " << cycle_n << endl;
    return cycle_n == 1;
}

//O(1)
void Graph::delete_vertex(int u) {
    if (exist_vertex(u)) this->vertex_available[u] = false;
}

//O(n)
void Graph::delete_edge(int u, int v) {
    if (exist_vertex(u) && exist_vertex(v) && exist_edge(u, v)) {
        this->graph[v][u] = -1;
        this->graph[u][v] = -1;
        --degree_vertex[u];
        --degree_vertex[v];
        if (degree_vertex[u] == 0) delete_vertex(u);
        if (degree_vertex[v] == 0) delete_vertex(v);
    }
}

//O(1)
bool Graph::exist_edge(int u, int v) {
    return exist_vertex(u) and exist_vertex(v) and this->graph[u][v] != -1;
}

//O(1)
bool Graph::exist_vertex(int u) {
    if (u == -1) return false;
    return this->vertex_available[u];
}

void Graph::writeOutput(ofstream& myfile) {
    myfile << this->graph.size() << endl;
    for (int i = 0, size = this->graph.size(); i < size; ++i) {
        for (int j = 0, size = this->graph[i].size(); j < size; ++j) {
            myfile << this->graph[i][j] << ' ';
        }
        myfile << endl;
    }
}

void Graph::readOutput() {
    string str;
    int num;
    getline(cin, str);
    for (int i = 0; i < n; ++i) {
        cout << i << endl;
        if (getline(cin, str)) {
            istringstream sstr(str);
            int n;
            while (sstr >> n) {
                add_edge(i, n);
            }
        }
    }
}

int Graph::getNumberComplex() {
    return this->complex_components;
}
