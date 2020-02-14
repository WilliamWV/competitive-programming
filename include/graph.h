#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include <map>
#include "mm.h"
#include "util.h"

//Graph represented as a matrix

typedef struct graph{
    int** graph; 
    int nodes;
} Graph;

// Edge structure used on kruskal algorithm
typedef struct edge{
    int src;
    int dst;
    int weight;
} Edge;

typedef std::map<int, int> intmap;

Graph* init_graph(int nodes);

Edge* create_edge(int src, int dst, int weight);

void add_arc(Graph* graph, int src, int dst, int weight);

void add_edge(Graph* graph, int src, int dst, int weight);

//Edge's nodes identification is a sequence from 0 to n-1 (n = number of nodes)
Graph* mount_graph(std::vector<Edge*> edges);

void rm_edge(Graph* graph, int src, int dst);

void print_graph(Graph* graph);

void dfs(Graph* graph, int src);

void bfs(Graph* graph, int src);

// The graph must not contain negative weight edges
int dijkstra(Graph* graph, int src, int dst);

std::vector<int> complete_dijkstra(Graph* graph, int src);

Graph* dijkstra_graph(Graph* graph, int src);

// May only work when the graph is undirected
int kruskal_cost(Graph* graph);

Graph* mst(Graph* graph);

std::vector<std::vector<int>> floyd_warshall(Graph* graph);

#endif