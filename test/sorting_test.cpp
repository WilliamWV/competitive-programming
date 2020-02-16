#include "../include/sorting.h"
#include "../include/util.h"
#include <gtest/gtest.h>

using namespace std;

vector<int> u1 = {4, 6, 2, 1, 6, 7, 2, 9, 10, -1, 0, 4, 6};
vector<int> u2 = {4};
vector<int> u3 = {4, 6, 2, 1, 6, 7, 2, 9, 10, -1, 0, 4, 6, 0, 0, 2, 4, 876, -13, 87, 23, 0, 14, -12};
vector<int> u4 = {4, 2, 1, 6, 7, 9, 10, -1, 0};
vector<int> u5 = {-1, -1, -1, 0, -1, -1, 2, -4};

vector<int> o1 = {-1, 0, 1, 2, 2, 4, 4, 6, 6, 6, 7, 9, 10};
vector<int> o2 = {4};
vector<int> o3 = {-13, -12, -1, 0, 0, 0, 0, 1, 2, 2, 2, 4, 4, 4, 6, 6, 6, 7, 9, 10, 14, 23, 87, 876};
vector<int> o4 = {-1, 0, 1, 2, 4, 6, 7, 9, 10};
vector<int> o5 = {-4, -1, -1, -1, -1, -1, 0, 2};

void reinitVectors(){
    u1 = {4, 6, 2, 1, 6, 7, 2, 9, 10, -1, 0, 4, 6};
    u2 = {4};
    u3 = {4, 6, 2, 1, 6, 7, 2, 9, 10, -1, 0, 4, 6, 0, 0, 2, 4, 876, -13, 87, 23, 0, 14, -12};
    u4 = {4, 2, 1, 6, 7, 9, 10, -1, 0};
    u5 = {-1, -1, -1, 0, -1, -1, 2, -4};
}


TEST(QuicksortTest, QSTest){
    reinitVectors();

    quicksort(u1);
    quicksort(u2);
    quicksort(u3);
    quicksort(u4);
    quicksort(u5);
    
    ASSERT_TRUE(vectorCompare(o1, u1));
    ASSERT_TRUE(vectorCompare(o2, u2));
    ASSERT_TRUE(vectorCompare(o3, u3));
    ASSERT_TRUE(vectorCompare(o4, u4));
    ASSERT_TRUE(vectorCompare(o5, u5));

}

TEST(MergesortTest, MSTest){
    reinitVectors();

    mergesort(u1);
    mergesort(u2);
    mergesort(u3);
    mergesort(u4);
    mergesort(u5);
    
    ASSERT_TRUE(vectorCompare(o1, u1));
    ASSERT_TRUE(vectorCompare(o2, u2));
    ASSERT_TRUE(vectorCompare(o3, u3));
    ASSERT_TRUE(vectorCompare(o4, u4));
    ASSERT_TRUE(vectorCompare(o5, u5));
}

TEST(BublesortTest, BSTest){
    reinitVectors();

    bubblesort(u1);
    bubblesort(u2);
    bubblesort(u3);
    bubblesort(u4);
    bubblesort(u5);
    
    ASSERT_TRUE(vectorCompare(o1, u1));
    ASSERT_TRUE(vectorCompare(o2, u2));
    ASSERT_TRUE(vectorCompare(o3, u3));
    ASSERT_TRUE(vectorCompare(o4, u4));
    ASSERT_TRUE(vectorCompare(o5, u5));
}

TEST(IssortedTest, sorted){
    ASSERT_TRUE(is_sorted(o1));
    ASSERT_TRUE(is_sorted(o2));
    ASSERT_TRUE(is_sorted(o3));
    ASSERT_TRUE(is_sorted(o4));
    ASSERT_TRUE(is_sorted(o5));
}

TEST(IssortedTest, unsorted){
    reinitVectors();
    
    ASSERT_FALSE(is_sorted(u1));
    ASSERT_TRUE(is_sorted(u2)); // single element vector
    ASSERT_FALSE(is_sorted(u3));
    ASSERT_FALSE(is_sorted(u4));
    ASSERT_FALSE(is_sorted(u5));
    
}