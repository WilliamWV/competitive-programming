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

TEST(dijkstraTest, nodesDistance){
    if(!graph_ready) init_test_graphs();

    ASSERT_EQ(3, dijkstra(g1, 0, 6));
    ASSERT_EQ(19, dijkstra(g1, 4, 8));
    ASSERT_EQ(10, dijkstra(g1, 3, 6));
    ASSERT_EQ(7, dijkstra(g1, 2, 7));
    ASSERT_EQ(9, dijkstra(g1, 1, 3));
    ASSERT_EQ(9, dijkstra(g1, 4, 2));
    ASSERT_EQ(14, dijkstra(g1, 5, 8));
    ASSERT_EQ(9, dijkstra(g1, 7, 5));
    
    ASSERT_EQ(INT_MAX, dijkstra(g2, 2, 0));
    ASSERT_EQ(2, dijkstra(g2, 0, 2));
    ASSERT_EQ(2, dijkstra(g2, 4, 5));
    ASSERT_EQ(1, dijkstra(g2, 1, 5));
    ASSERT_EQ(3, dijkstra(g2, 3, 2));
    
}

TEST(dijkstraTest, allDistances){
    if(!graph_ready) init_test_graphs();

    vector<int> expected_g1_from_0 = {0, 2, 1, 7, 8, 3, 3, 6, 11};
    vector<int> actual_g1_from_0 = complete_dijkstra(g1, 0);

    vector<int> expected_g1_from_3 = {7, 9, 8, 0, 1, 4, 10, 13, 18};
    vector<int> actual_g1_from_3 = complete_dijkstra(g1, 3);
    
    vector<int> expected_g1_from_6 = {3, 1, 4, 10, 11, 6, 0, 5, 14};
    vector<int> actual_g1_from_6 = complete_dijkstra(g1, 6);
    
    vector<int> expected_g2_from_1 = {INT_MAX, 0, 1, INT_MAX, INT_MAX, 1};
    vector<int> actual_g2_from_1 = complete_dijkstra(g2, 1);
    
    vector<int> expected_g2_from_4 = {2, 3, 4, 1, 0, 2};
    vector<int> actual_g2_from_4 = complete_dijkstra(g2, 4);
    
    ASSERT_TRUE(vectorCompare(actual_g1_from_0, expected_g1_from_0));
    ASSERT_TRUE(vectorCompare(actual_g1_from_3, expected_g1_from_3));
    ASSERT_TRUE(vectorCompare(actual_g1_from_6, expected_g1_from_6));
    ASSERT_TRUE(vectorCompare(actual_g2_from_1, expected_g2_from_1));
    ASSERT_TRUE(vectorCompare(actual_g2_from_4, expected_g2_from_4));

}

TEST(dijkstraTest, dijkstraTree){
    if(!graph_ready) init_test_graphs();

    Graph* actual_g1_dijkstra_from_0 = dijkstra_graph(g1, 0);
    Graph* expected_g1_dijkstra_from_0;
    expected_g1_dijkstra_from_0 = init_graph(9);
    add_arc(expected_g1_dijkstra_from_0, 0, 1, 2);
    add_arc(expected_g1_dijkstra_from_0, 0, 2, 1);
    add_arc(expected_g1_dijkstra_from_0, 0, 5, 3);
    add_arc(expected_g1_dijkstra_from_0, 0, 8, 11);
    add_arc(expected_g1_dijkstra_from_0, 1, 6, 1);
    add_arc(expected_g1_dijkstra_from_0, 1, 7, 4);
    add_arc(expected_g1_dijkstra_from_0, 5, 3, 4);
    add_arc(expected_g1_dijkstra_from_0, 3, 4, 1);
    
    Graph* actual_g2_dijkstra_from_3 = dijkstra_graph(g2, 3);
    Graph* expected_g2_dijkstra_from_3;
    expected_g2_dijkstra_from_3 = init_graph(6);
    add_arc(expected_g2_dijkstra_from_3, 3, 0, 1);
    add_arc(expected_g2_dijkstra_from_3, 3, 5, 1);
    add_arc(expected_g2_dijkstra_from_3, 0, 1, 1);
    add_arc(expected_g2_dijkstra_from_3, 1, 2, 1);
    
    ASSERT_TRUE(graphsEqual(actual_g1_dijkstra_from_0, expected_g1_dijkstra_from_0));
    ASSERT_TRUE(graphsEqual(actual_g2_dijkstra_from_3, expected_g2_dijkstra_from_3));
    

}

TEST(MSTTest, KruskalTest){
    ASSERT_EQ(27, kruskal_cost(g1));
}

TEST(MSTTest, MSTTest){
    Graph* actual_g1_mst = mst(g1);
    Graph* expected_g1_mst;
    expected_g1_mst = init_graph(9);
    add_edge(expected_g1_mst, 0, 1, 2);
    add_edge(expected_g1_mst, 0, 2, 1);
    add_edge(expected_g1_mst, 0, 5, 3);
    add_edge(expected_g1_mst, 0, 8, 11);
    add_edge(expected_g1_mst, 1, 7, 4);
    add_edge(expected_g1_mst, 1, 6, 1);
    add_edge(expected_g1_mst, 3, 4, 1);
    add_edge(expected_g1_mst, 5, 3, 4);
    
    ASSERT_TRUE(graphsEqual(actual_g1_mst, expected_g1_mst));

}

bool matEqual(vector<vector<int>> v1, vector<vector<int>> v2){
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); i++){
        if(v1[i].size() != v2[i].size()) return false;
        for (int j = 0; j < v1[i].size(); j++){
            if(v1[i][j] != v2[i][j]) return false;
        }
    }
    return true;
}

TEST(FloydWarshallTest, FloydWarshallTest){
    vector<vector<int>> actual_fw_g1 = floyd_warshall(g1);
    vector<vector<int>> expected_fw_g1 = {
        {0, 2, 1, 7, 8, 3, 3, 6, 11},
        {2, 0, 3, 9, 10, 5, 1, 4, 13},
        {1, 3, 0, 8, 9, 4, 4, 7, 12},
        {7, 9, 8, 0, 1, 4, 10, 13, 18},
        {8, 10, 9, 1, 0, 5, 11, 14, 19},
        {3, 5, 4, 4, 5, 0, 6, 9, 14},
        {3, 1, 4, 10, 11, 6, 0, 5, 14},
        {6, 4, 7, 13, 14, 9, 5, 0, 17},
        {11, 13, 12, 18, 19, 14, 14, 17, 0}
    };

    vector<vector<int>> actual_fw_g2 = floyd_warshall(g2);
    vector<vector<int>> expected_fw_g2 = {
        {0, 1, 2, INT_MAX, INT_MAX, 2},
        {INT_MAX, 0, 1, INT_MAX, INT_MAX, 1},
        {INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX, INT_MAX},
        {1, 2, 3, 0, INT_MAX, 1},
        {2, 3, 4, 1, 0, 2},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},
        
    };
    
    ASSERT_TRUE(matEqual(actual_fw_g1, expected_fw_g1));
    ASSERT_TRUE(matEqual(actual_fw_g2, expected_fw_g2));
}