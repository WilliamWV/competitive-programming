#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include "mm.h"
#include "util.h"

//Graph represented as a matrix

typedef struct{
    int** graph; 
    int nodes;
} Graph;

Graph* init_graph(int nodes);

void add_arc(Graph* graph, int src, int dst, int weight);

void add_edge(Graph* graph, int src, int dst, int weight);

void rm_edge(Graph* graph, int src, int dst);

void print_graph(Graph* graph);

void dfs(Graph* graph, int src);

void bfs(Graph* graph, int src);

int dijkstra(Graph* graph, int src, int dst);

std::vector<int> complete_dijkstra(Graph* graph, int src);

Graph* dijkstra_graph(Graph* graph, int src);

int kruskal_cost(Graph* graph);

Graph* mst(Graph* graph);

int** floyd_warshall(Graph* graph);