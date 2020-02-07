#include <iostream>
#include <vector>

using namespace std;

//Graph represented as a matrix

typedef struct{
    int** graph; 
    int nodes;
} Graph;

void dfs(Graph graph, int src);
void bfs(Graph graph, int src);
int dijkstra(Graph graph, int src, int dst);
int* complete_dijkstra(Graph graph, int src);
Graph dijkstra_graph(Graph graph, int src);
int kruskal_cost(Graph graph);
Graph mst(Graph graph);
int** floyd_warshall(Graph graph);