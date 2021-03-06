#include "../include/graph.h"

using namespace std;

Graph* init_graph(int nodes){
    Graph* new_graph = (Graph*) allocate(sizeof(Graph));
    new_graph->nodes = nodes;
    new_graph->graph = (int**) allocate(sizeof(int*) * nodes);
    for (int i = 0; i < nodes; i++){
        new_graph->graph[i] = (int*) allocate(sizeof(int) * nodes);
        for (int j = 0; j < nodes; j++){
            if (i == j){
                new_graph->graph[i][j] = 0;
            }
            else{
                new_graph->graph[i][j] = INT_MAX;
            }
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


vector<int> dfs(Graph* graph, int src){
    stack<int> node_stack;
    vector<bool> visited_nodes (graph->nodes, false);
    vector<int> answer;

    node_stack.push(src);
    while (!node_stack.empty()){
        int current_node = node_stack.top(); 
        node_stack.pop();
        if (!visited_nodes[current_node]){
            visited_nodes[current_node] = true;
            answer.push_back(current_node);
            for (int i = 0; i < graph->nodes; i++){
                if (graph->graph[current_node][i] < INT_MAX && !visited_nodes[i]){
                    node_stack.push(i);
                }
            }
        }
    }
    return answer;
}


vector<int> bfs(Graph* graph, int src){
    
    vector<int> answer;
    queue<int> node_queue;
    vector<bool> visited_nodes (graph->nodes, false);
    
    node_queue.push(src);
    while (!node_queue.empty()){
        int current_node = node_queue.front(); 
        node_queue.pop();
        if (!visited_nodes[current_node]){ // needs to recheck because the node can reapear due to a cycle
            visited_nodes[current_node] = true;
            answer.push_back(current_node);
            for (int i = 0; i < graph->nodes; i++){
                if (graph->graph[current_node][i] < INT_MAX && !visited_nodes[i]){
                    node_queue.push(i);
                }
            }
        }
    }
    return answer;
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
        return INT_MAX;
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

vector<vector<int>> floyd_warshall(Graph* graph){
    vector<vector<int>> dist;

    for (int i = 0; i < graph->nodes; i++){
        vector<int> temp;
        dist.push_back(temp);
        for(int j = 0; j < graph->nodes; j++){
            dist[i].push_back(graph->graph[i][j]);
        }
    }

    for(int i = 0; i < graph->nodes; i++){
        for(int j = 0; j < graph->nodes; j++){
            for (int k = 0; k < graph->nodes; k++){
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX &&
                    dist[i][j] > dist[i][k] + dist[k][j]
                    ){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

bool graphsEqual(Graph* g1, Graph* g2){
    if(g1->nodes != g2->nodes) return false;

    for (int i = 0; i < g1->nodes; i++){
        for (int j = 0; j < g1->nodes; j++){
            if(g1->graph[i][j] != g2->graph[i][j]) return false;
        }
    }
    return true;
}
