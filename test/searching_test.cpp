#include "../include/searching.h"
#include <gtest/gtest.h>

using namespace std;

vector<int> ord_1 = {1, 4, 8, 9, 10, 11, 12, 18, 21};
vector<int> ord_2 = {0, 9, 192, 92830, 12723937, 128384621};
vector<int> ord_3 = {1, 2, 8, 9, 17, 93};


TEST(BinarySearchTest, ElementNotPresent){
    ASSERT_EQ(-1, binary_search(ord_1, 7));
    ASSERT_EQ(-1, binary_search(ord_2, 100));
    ASSERT_EQ(-1, binary_search(ord_3, 94));
    ASSERT_EQ(-1, binary_search(ord_1, -2));
    ASSERT_EQ(-1, binary_search(ord_2, 1));
}

TEST(BinarySearchTest, ElementPresent){
    ASSERT_EQ(0, binary_search(ord_1, 1));
    ASSERT_EQ(8, binary_search(ord_1, 21));
    ASSERT_EQ(2, binary_search(ord_2, 192));
    ASSERT_EQ(4, binary_search(ord_3, 17));
    ASSERT_EQ(1, binary_search(ord_2, 9));
    
}

vector<int> unord_1 = {1, 4, 8, 9, 10, 11, 12, 18, 21};
vector<int> unord_2 = {1, 5, 8, 2, 3, -9, 19};
vector<int> unord_3 = {42, 9, 1, 56, 2, 3, 78, 1, 0};
    

TEST(LinearSearchTest,ElementNotPresent){
    ASSERT_EQ(-1, linear_search(unord_1, 0));
    ASSERT_EQ(-1, linear_search(unord_2, 25));
    ASSERT_EQ(-1, linear_search(unord_3, 13));
    ASSERT_EQ(-1, linear_search(unord_1, -3));
    ASSERT_EQ(-1, linear_search(unord_2, 12));
    
}

TEST(LinearSearchTest, ElementPresent){
    ASSERT_EQ(0, linear_search(unord_1, 1));
    ASSERT_EQ(2, linear_search(unord_1, 8));
    ASSERT_EQ(6, linear_search(unord_2, 19));
    ASSERT_EQ(3, linear_search(unord_3, 56));
    ASSERT_EQ(5, linear_search(unord_2, -9));
    
}
