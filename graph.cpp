#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include "mm.h"

using namespace std;

void print_vec(vector<int> arr, string title){
    cout<<title<<endl;
    for (int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

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



int dijkstra(Graph* graph, int src, int dst){
    vector<int> dists (graph->nodes, INT_MAX);
    vector<bool> visited (graph->nodes, false);
    dists[src] = 0;

    int current_node = src;
    while (!visited[dst] && current_node > -1){
        visited[current_node] = true;
        for (int i = 0; i < graph->nodes; i++){
            if (
                    graph->graph[current_node][i] < INT_MAX && 
                    graph->graph[current_node][i] + dists[current_node] < dists[i]
                ){
                dists[i] = graph->graph[current_node][i] + dists[current_node];
            }
        }
        int min_dist = INT_MAX;
        current_node = -1;
        for (int i = 0; i < graph->nodes; i++){
            if (!visited[i] && dists[i]< min_dist){
                min_dist = dists[i];
                current_node = i;
            }
        }
    }
    if (!visited[dst]){//unreachable
        return -1;
    }
    return dists[dst];

}

vector<int> complete_dijkstra(Graph* graph, int src){
    vector<int> dists (graph->nodes, INT_MAX);
    vector<bool> visited (graph->nodes, false);
    dists[src] = 0;

    int current_node = src;
    while (current_node > -1){
        visited[current_node] = true;
        for (int i = 0; i < graph->nodes; i++){
            if (
                    graph->graph[current_node][i] < INT_MAX && 
                    graph->graph[current_node][i] + dists[current_node] < dists[i]
                ){
                dists[i] = graph->graph[current_node][i] + dists[current_node];
            }
        }
        int min_dist = INT_MAX;
        current_node = -1;
        for (int i = 0; i < graph->nodes; i++){
            if (!visited[i] && dists[i]< min_dist){
                min_dist = dists[i];
                current_node = i;
            }
        }
    }

    return dists;
}

Graph* dijkstra_graph(Graph* graph, int src){

    Graph* dk_graph = init_graph(graph->nodes);
    vector<int> dists (graph->nodes, INT_MAX);
    vector<int> parent(graph->nodes, -1); // parent on dijkstra tree
    vector<bool> visited (graph->nodes, false);
    dists[src] = 0;

    int current_node = src;
    while (current_node > -1){

        visited[current_node] = true;
        for (int i = 0; i < graph->nodes; i++){
            if (
                    graph->graph[current_node][i] < INT_MAX && 
                    graph->graph[current_node][i] + dists[current_node] < dists[i]
                ){
                
                dists[i] = graph->graph[current_node][i] + dists[current_node];
                parent[i] = current_node;
            }
        }
        int min_dist = INT_MAX;
        current_node = -1;
        for (int i = 0; i < graph->nodes; i++){
            if (!visited[i] && dists[i]< min_dist){
                min_dist = dists[i];
                current_node = i;
            }
        }
    }

    for (int i = 0; i < graph->nodes; i++){
        if(parent[i] >= 0){
            add_arc(dk_graph, parent[i], i, graph->graph[parent[i]][i]);
        }
    }
    

    return dk_graph;
}

int kruskal_cost(Graph* graph);
Graph* mst(Graph* graph);
int** floyd_warshall(Graph* graph);


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

    cout<<"Distance between 0 and 1 = "<<dijkstra(t_graph, 0, 1)<<endl;
    cout<<"Distance between 0 and 8 = "<<dijkstra(t_graph, 0, 8)<<endl;
    cout<<"Distance between 0 and 2 = "<<dijkstra(t_graph, 0, 2)<<endl;
    cout<<"Distance between 4 and 8 = "<<dijkstra(t_graph, 4, 8)<<endl;
    cout<<"Distance between 3 and 6 = "<<dijkstra(t_graph, 3, 6)<<endl;
    cout<<"Distance between 1 and 7 = "<<dijkstra(t_graph, 1, 7)<<endl;
    cout<<"Distance between 5 and 2 = "<<dijkstra(t_graph, 5, 2)<<endl;
    
    print_vec(complete_dijkstra(t_graph, 1), "Distance to all nodes from 1: ");

    cout<<"Graph of shortest path generated by dijkstra from 5: "<<endl;
    print_graph(dijkstra_graph(t_graph, 5));

    deallocate_all();
}


//Compile with:
// g++ -O2 -o graph graph.cpp mm.cpp