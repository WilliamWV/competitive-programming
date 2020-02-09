#include "graph.h"

using namespace std;

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

Edge* create_edge(int src, int dst, int weight){
    Edge* new_edge = (Edge*) allocate(sizeof(Edge));
    new_edge->src = src;
    new_edge->dst = dst;
    new_edge->weight = weight;
    return new_edge;
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

vector<Edge*> build_edges(Graph* graph){
    vector<Edge*> edges;

    for (int i = 0; i < graph->nodes; i++){
        for (int j = i; j<graph->nodes; j++){
            if (graph->graph[i][j] < INT_MAX){
                edges.push_back(create_edge(i, j, graph->graph[i][j]));
            }
        }
    }
    return edges;
}

intmap build_subsets(Graph* graph){
    intmap subsets;
    for (int i = 0; i < graph->nodes; i++){
        subsets[i] = i;
    }
    return subsets;
}

bool compare_edges(Edge* e1, Edge* e2){
    return e1->weight < e2->weight;
}

void unite_subsets(intmap & subsets, int s1, int s2){
    int smaller = s1;
    int bigger = s2;
    if (s1 > s2){
        smaller = s2;
        bigger = s1;
    }
    for (intmap::iterator it = subsets.begin(); it != subsets.end(); it++){
        if (it->second == bigger){
            subsets[it->first] = smaller;
        }
    }
}

int subset_count(intmap subsets){
    int max_subset = 0;
    for (intmap::iterator it = subsets.begin(); it != subsets.end(); it++){
        if (it->second > max_subset){
            max_subset = it->second;
        }
    }
    return max_subset + 1;
}

int kruskal_cost(Graph* graph){

    vector<Edge*> edges = build_edges(graph);
    int edge_cost = 0;
    intmap subsets = build_subsets(graph);

    sort(edges.begin(), edges.end(), compare_edges);

    int edge_index = 0;
    while (edge_index < edges.size() && subset_count(subsets) > 1){
        Edge* next_edge = edges[edge_index];
        if (subsets[next_edge->dst] != subsets[next_edge->src]){
            unite_subsets(subsets, subsets[next_edge->dst], subsets[next_edge->src]);
            edge_cost+= next_edge->weight;
        }
        edge_index++;
    }
    return edge_cost;

}

Graph* mount_graph(vector<Edge*> edges){
    int n = 0;
    for (int i = 0; i < edges.size(); i++){
        n = max(edges[i]->src, edges[i]->dst);
    }
    Graph* mounted = init_graph(n+1);
    for (int i = 0; i < edges.size(); i++){
        add_edge(mounted, edges[i]->src, edges[i]->dst, edges[i]->weight);
    }
    return mounted;
}

Graph* kruskal_mst(Graph* graph){

    vector<Edge*> edges = build_edges(graph);
    vector<Edge*> result;
    intmap subsets = build_subsets(graph);

    sort(edges.begin(), edges.end(), compare_edges);

    int edge_index = 0;
    while (edge_index < edges.size() && subset_count(subsets) > 1){
        Edge* next_edge = edges[edge_index];
        if (subsets[next_edge->dst] != subsets[next_edge->src]){
            unite_subsets(subsets, subsets[next_edge->dst], subsets[next_edge->src]);
            result.push_back(next_edge);
        }
        edge_index++;
    }
    return mount_graph(result);
}

Graph* mst(Graph* graph){
    return kruskal_mst(graph);
}

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

    cout<<"The cost of the minimum spamming tree is: "<<kruskal_cost(t_graph)<<endl;
    cout<<"The MST graph is: ";
    print_graph(mst(t_graph));

    deallocate_all();
}


//Compile with:
// g++ -O2 -o graph graph.cpp mm.cpp