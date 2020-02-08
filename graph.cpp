#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include "mm.h"

using namespace std;

//Graph represented as a matrix

typedef struct{
    int** graph; 
    int nodes;
} Graph;

Graph* init_graph(int nodes){
    Graph* new_graph = (Graph*) allocate(sizeof(Graph));
    new_graph->nodes = nodes;
    new_graph->graph = (int**) allocate(sizeof(int*) * nodes);
    for (int i = 0; i < nodes; i++){
        new_graph->graph[i] = (int*) allocate(sizeof(int) * nodes);
        for (int j = 0; j < nodes; j++){
            new_graph->graph[i][j] = INT_MAX;
        }
    }
    return new_graph;
}

void add_arc(Graph* graph, int src, int dst, int weight){
    // keep only the edge with smallest weight
    if (graph->graph[src][dst] > weight){
        graph->graph[src][dst] = weight;
    }

}

void add_edge(Graph* graph, int src, int dst, int weight){
    add_arc(graph, src, dst, weight);
    add_arc(graph, dst, src, weight);
}

void rm_edge(Graph* graph, int src, int dst){
    graph->graph[src][dst] = INT_MAX;
}

void print_graph(Graph* graph){
    cout<<"Printing a graph with "<<graph->nodes<<" nodes:"<<endl;
    for(int i = 0; i < graph->nodes; i++){
        cout<<"|";
        for(int j = 0; j < graph->nodes; j++){
            if (graph->graph[i][j] == INT_MAX){
                cout<<" -";
            } else {
                cout<<" "<< graph->graph[i][j];
            }
        }
        cout<<" |"<<endl;
    }
}


void dfs(Graph* graph, int src){
    stack<int> node_stack;
    vector<bool> visited_nodes (graph->nodes, false);
    bool first_node = true;
    cout<<"Navigating through the graph with DFS: "<<endl;
    node_stack.push(src);
    while (!node_stack.empty()){
        int current_node = node_stack.top(); 
        node_stack.pop();
        if (!visited_nodes[current_node]){
            visited_nodes[current_node] = true;
            if (!first_node){
                cout<<" - ";
            }
            else{
                first_node = false;
            }
            cout<<current_node;

            for (int i = 0; i < graph->nodes; i++){
                if (graph->graph[current_node][i] < INT_MAX && !visited_nodes[i]){
                    node_stack.push(i);
                }
            }
        }
    }
    cout<<endl;
}


void bfs(Graph* graph, int src){
    
    queue<int> node_queue;
    vector<bool> visited_nodes (graph->nodes, false);
    bool first_node = true;
    
    cout<<"Navigating through the graph with BFS: "<<endl;
    node_queue.push(src);
    while (!node_queue.empty()){
        int current_node = node_queue.front(); 
        node_queue.pop();
        if (!visited_nodes[current_node]){ // needs to recheck because the node can reapear due to a cycle
            visited_nodes[current_node] = true;
            if (first_node){
                first_node = false;
            }
            else{
                cout<<" - ";
            }
            cout<<current_node;
            for (int i = 0; i < graph->nodes; i++){
                if (graph->graph[current_node][i] < INT_MAX && !visited_nodes[i]){
                    node_queue.push(i);
                }
            }
        }
    }
    cout<<endl;
}

int dijkstra(Graph graph, int src, int dst);
int* complete_dijkstra(Graph graph, int src);
Graph* dijkstra_graph(Graph graph, int src);
int kruskal_cost(Graph graph);
Graph* mst(Graph graph);
int** floyd_warshall(Graph graph);


int main(){
    // Test graph:
    //       3 -[1]- 4 -[32]- 8
    //       |[4]      _[11]_/
    //       5--[3]--0/-[2]-1 -[4]- 7
    //              |[1]    |[1]
    //              2--[7]--6
    
    Graph* t_graph = init_graph(9);
    add_edge(t_graph, 0, 1, 2);
    add_edge(t_graph, 0, 5, 3);
    add_edge(t_graph, 0, 2, 1);
    add_edge(t_graph, 0, 8, 11);
    add_edge(t_graph, 1, 7, 4);
    add_edge(t_graph, 1, 6, 1);
    add_edge(t_graph, 2, 6, 7);
    add_edge(t_graph, 3, 4, 1);
    add_edge(t_graph, 3, 5, 4);
    add_edge(t_graph, 4, 8, 32);
    
    cout<<"Graph mounted"<<endl;
    print_graph(t_graph);
    dfs(t_graph, 0);
    bfs(t_graph, 0);


    deallocate_all();
}


//Compile with:
// g++ -O2 -o graph graph.cpp mm.cpp