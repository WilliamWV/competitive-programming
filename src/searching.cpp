#include "../include/searching.h"

using namespace std;

// Returns the index of the target element or -1 if not found
int binary_search(vector<int> & arr, int target){
    int l = 0; 
    int h = arr.size();
    while (l < h){
        int m = l + (h-l)/2;

        if (arr[m] == target)
            return m;

        if (arr[m] > target){
            h = m;
        } else{
            l = m + 1; 
        }

    }
    return -1;
}

int linear_search(vector<int> & arr, int target){
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] == target) return i;
    }
    return -1;
}
