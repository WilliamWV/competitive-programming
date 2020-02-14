#include "../include/searching.h"
#include <gtest/gtest.h>

using namespace std;

vector<int> o1 = {1, 4, 8, 9, 10, 11, 12, 18, 21};
vector<int> o2 = {0, 9, 192, 92830, 12723937, 128384621};
vector<int> o3 = {1, 2, 8, 9, 17, 93};


TEST(BinarySearchTest, ElementNotPresent){
    ASSERT_EQ(-1, binary_search(o1, 7));
    ASSERT_EQ(-1, binary_search(o2, 100));
    ASSERT_EQ(-1, binary_search(o3, 94));
    ASSERT_EQ(-1, binary_search(o1, -2));
    ASSERT_EQ(-1, binary_search(o2, 1));
}

TEST(BinarySearchTest, ElementPresent){
    ASSERT_EQ(0, binary_search(o1, 1));
    ASSERT_EQ(8, binary_search(o1, 21));
    ASSERT_EQ(2, binary_search(o2, 192));
    ASSERT_EQ(4, binary_search(o3, 17));
    ASSERT_EQ(1, binary_search(o2, 9));
    
}

vector<int> u1 = {1, 4, 8, 9, 10, 11, 12, 18, 21};
vector<int> u2 = {1, 5, 8, 2, 3, -9, 19};
vector<int> u3 = {42, 9, 1, 56, 2, 3, 78, 1, 0};
    

TEST(LinearSearchTest,ElementNotPresent){
    ASSERT_EQ(-1, linear_search(u1, 0));
    ASSERT_EQ(-1, linear_search(u2, 25));
    ASSERT_EQ(-1, linear_search(u3, 13));
    ASSERT_EQ(-1, linear_search(u1, -3));
    ASSERT_EQ(-1, linear_search(u2, 12));
    
}

TEST(LinearSearchTest, ElementPresent){
    ASSERT_EQ(0, linear_search(u1, 1));
    ASSERT_EQ(2, linear_search(u1, 8));
    ASSERT_EQ(6, linear_search(u2, 19));
    ASSERT_EQ(3, linear_search(u3, 56));
    ASSERT_EQ(5, linear_search(u2, -9));
    
}
