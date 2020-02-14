#include "../include/sorting.h"

using namespace std;

int test_sorting(){
    
    vector<int> v1 = {4, 6, 2, 1, 6, 7, 2, 9, 10, -1, 0, 4, 6};
    vector<int> v2 = {4};
    vector<int> v3 = {4, 6, 2, 1, 6, 7, 2, 9, 10, -1, 0, 4, 6, 0, 0, 2, 4, 876, -13, 87, 23, 0, 14, -12};
    vector<int> v4 = {4, 2, 1, 6, 7, 9, 10, -1, 0};
    vector<int> v5 = {-1, -1, -1, 0, -1, -1, 2, -4};
    

    
    print_vec(v1, "Initial vector");
    sort(v1);
    print_vec(v1, "Final vector");

    print_vec(v2, "Initial vector");
    sort(v2);
    print_vec(v2, "Final vector");

    print_vec(v3, "Initial vector");
    sort(v3);
    print_vec(v3, "Final vector");

    print_vec(v4, "Initial vector");
    sort(v4);
    print_vec(v4, "Final vector");

    print_vec(v5, "Initial vector");
    sort(v5);
    print_vec(v5, "Final vector");

}