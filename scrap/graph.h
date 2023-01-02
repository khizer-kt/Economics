#pragma once
#include <iostream>
#include <sstream>

class Graph {
private:
    int num_nodes;
    int num_edges;
    int* adjacency_list;
    int* weights;

public:
    Graph(int num_nodes, int num_edges);
    void add_edge(int u, int v, int w);
    void remove_edge(int u, int v);
    int get_weight(int u, int v);
    void set_weight(int u, int v, int w);
    void print();
};

Graph::Graph(int num_nodes, int num_edges) {
    this->num_nodes = num_nodes;
    this->num_edges = num_edges;
    adjacency_list = new int[num_nodes * num_nodes];
    weights = new int[num_nodes * num_nodes];
    for (int i = 0; i < num_nodes * num_nodes; i++) {
        adjacency_list[i] = 0;
        weights[i] = 0;
    }
}

void Graph::add_edge(int u, int v, int w) {
    adjacency_list[u * num_nodes + v] = 1;
    weights[u * num_nodes + v] = w;
}

void Graph::remove_edge(int u, int v) {
    adjacency_list[u * num_nodes + v] = 0;
    weights[u * num_nodes + v] = 0;
}

int Graph::get_weight(int u, int v) {
    return weights[u * num_nodes + v];
}

void Graph::set_weight(int u, int v, int w) {
    weights[u * num_nodes + v] = w;
}

void Graph::print() {
    for (int u = 0; u < num_nodes; u++) {
        for (int v = 0; v < num_nodes; v++) {
            if (adjacency_list[u * num_nodes + v] == 1) {
                std::cout << u << " -> " << v << ": " << weights[u * num_nodes + v] << std::endl;
            }
        }
    }
}

void recommend_items(int user_id, const Graph& g) {
    int recommended_items[g.num_nodes];
    int num_recommended_items = 0;
    for (int v = 0; v < g.num_nodes; v++) {
        if (g.get_weight(user_id, v) > 0) {
            // v is a similar user to user_id, so find items that v has purchased or liked
            for (int u = 0; u < g.num_nodes; u++) {
                if (g.get_weight(v, u) > 0) {
                    // u is an item that v has purchased or liked, so recommend it to user_id
                    bool already_recommended = false;
                    for (int i = 0; i < num_recommended_items; i++) {
                        if (recommended_items[i] == u) {
                            already_recommended = true;
                            break;
                        }
                    }
                    if (!already_recommended) {
                        recommended_items[num_recommended_items++] = u;
                    }
                }
            }
        }
    }
    std::cout << "Recommendations for user " << user_id << ":" << std::endl;
    for (int i = 0; i < num_recommended_items; i++) {
        std::cout << recommended_items[i] << std::endl;
    }
}

int main() {
    Graph g(5, 7);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 1);
    g.add_edge(1, 0, 1);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 3, 1);
    g.add_edge(2, 0, 1);
    g.add_edge(2, 1, 1);
    g.add_edge(2, 3, 1);
    g.add_edge(3, 1

