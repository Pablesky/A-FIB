#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    Graph();
    Graph(int n);
    Graph(const Graph& g);
    ~Graph();
    void add_edge(int v, int u);

    void delete_vertex(int u);
    void delete_edge(int v, int u);

    int num_vertices();
    int num_edges();
    int num_cc();
    bool is_complex(int cc);

    void get_connected_components();
    void get_complex_ccs();
    void read();
    void write();
    void write_CCs();

    bool exist_edge(int u, int v);
    bool exist_vertex(int u);
    
private:
    int n, m;
    vector< vector<int> > graph;
    vector< vector< pair<bool,vector<int> > > > CC_graphs;
    vector<bool> visited;
    vector<bool> complex_cc;
    int connected_components;

    void dfs_util(int v, vector<bool>& visited_dfs);
    bool dfs_is_tree(int v, int parent, vector<bool>& visited_tree, const vector<pair<bool,vector<int> > >& CC_graph);
    void DFSCycle(const vector<pair<bool,vector<int> >>& CC_graph, int u, int p, vector<int>& color,
                         vector<int>& par, int& cyclenumber);

    bool is_unicyclic(const vector<pair<bool,vector<int> >>& CC_graph);
    bool is_tree(const vector<pair<bool,vector<int> >>& CC_graph);
};
