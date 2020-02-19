#include "../include/graph.h"
#include "../include/util.h"
#include <gtest/gtest.h>

using namespace std;

// g1:
//       3 -[1]- 4 -[32]- 8
//       |[4]      _[11]_/
//       5--[3]--0/-[2]-1 -[4]- 7
//              |[1]    |[1]
//              2--[7]--6

Graph* g1;

// g2:
//  
//              0->1->2
//              î  V
//           4->3->5


Graph* g2;

bool graph_ready = false;

void init_test_graphs(){
    g1 = init_graph(9);
    add_edge(g1, 0, 1, 2);
    add_edge(g1, 0, 5, 3);
    add_edge(g1, 0, 2, 1);
    add_edge(g1, 0, 8, 11);
    add_edge(g1, 1, 7, 4);
    add_edge(g1, 1, 6, 1);
    add_edge(g1, 2, 6, 7);
    add_edge(g1, 3, 4, 1);
    add_edge(g1, 3, 5, 4);
    add_edge(g1, 4, 8, 32);

    g2 = init_graph(6);
    add_arc(g2, 0, 1, 1);
    add_arc(g2, 1, 2, 1);
    add_arc(g2, 1, 5, 1);
    add_arc(g2, 3, 0, 1);
    add_arc(g2, 4, 3, 1);
    add_arc(g2, 3, 5, 1);
    
}


TEST(dfsTest, dfsTest){
    if(!graph_ready) init_test_graphs();

    vector<int> expected_g1_from_0 = {0, 8, 4, 3, 5, 2, 6, 1, 7};
    vector<int> actual_g1_from_0 = dfs(g1, 0);

    vector<int> expected_g1_from_3 = {3, 5, 0, 8, 4, 2, 6, 1, 7};
    vector<int> actual_g1_from_3 = dfs(g1, 3);
    
    vector<int> expected_g1_from_6 = {6, 2, 0, 8, 4, 3, 5, 1, 7};
    vector<int> actual_g1_from_6 = dfs(g1, 6);
    
    vector<int> expected_g2_from_1 = {1, 5, 2};
    vector<int> actual_g2_from_1 = dfs(g2, 1);
    
    vector<int> expected_g2_from_4 = {4, 3, 5, 0, 1, 2};
    vector<int> actual_g2_from_4 = dfs(g2, 4);
    
    ASSERT_TRUE(vectorCompare(actual_g1_from_0, expected_g1_from_0));
    ASSERT_TRUE(vectorCompare(actual_g1_from_3, expected_g1_from_3));
    ASSERT_TRUE(vectorCompare(actual_g1_from_6, expected_g1_from_6));
    ASSERT_TRUE(vectorCompare(actual_g2_from_1, expected_g2_from_1));
    ASSERT_TRUE(vectorCompare(actual_g2_from_4, expected_g2_from_4));
    

}

TEST(bfsTest, bfsTest){
    if(!graph_ready) init_test_graphs();

    vector<int> expected_g1_from_0 = {0, 1, 2, 5, 8, 6, 7, 3, 4};
    vector<int> actual_g1_from_0 = bfs(g1, 0);

    vector<int> expected_g1_from_3 = {3, 4, 5, 8, 0, 1, 2, 6, 7};
    vector<int> actual_g1_from_3 = bfs(g1, 3);
    
    vector<int> expected_g1_from_6 = {6, 1, 2, 0, 7, 5, 8, 3, 4};
    vector<int> actual_g1_from_6 = bfs(g1, 6);
    
    vector<int> expected_g2_from_1 = {1, 2, 5};
    vector<int> actual_g2_from_1 = bfs(g2, 1);
    
    vector<int> expected_g2_from_4 = {4, 3, 0, 5, 1, 2};
    vector<int> actual_g2_from_4 = bfs(g2, 4);
    

    ASSERT_TRUE(vectorCompare(actual_g1_from_0, expected_g1_from_0));
    ASSERT_TRUE(vectorCompare(actual_g1_from_3, expected_g1_from_3));
    ASSERT_TRUE(vectorCompare(actual_g1_from_6, expected_g1_from_6));
    ASSERT_TRUE(vectorCompare(actual_g2_from_1, expected_g2_from_1));
    ASSERT_TRUE(vectorCompare(actual_g2_from_4, expected_g2_from_4));
    
}

//void dfs(Graph* graph, int src);
//void bfs(Graph* graph, int src);
// The graph must not contain negative weight edges
//int dijkstra(Graph* graph, int src, int dst);
//std::vector<int> complete_dijkstra(Graph* graph, int src);
//Graph* dijkstra_graph(Graph* graph, int src);
// May only work when the graph is undirected
//int kruskal_cost(Graph* graph);
//Graph* mst(Graph* graph);
//std::vector<std::vector<int>> floyd_warshall(Graph* graph);