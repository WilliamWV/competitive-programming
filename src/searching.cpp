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

int main(){
    vector<int> o1 = {1, 4, 8, 9, 10, 11, 12, 18, 21};
    vector<int> o2 = {0, 9, 192, 92830, 12723937, 128384621};
    vector<int> o3 = {1, 2, 8, 9, 17, 93};
    cout<< "BINARY SEARCH" <<endl;
    cout<< "Index of element 8 on o1: " << binary_search(o1, 8)<<endl;
    cout<< "Index of element 12 on o1: " << binary_search(o1, 12)<<endl;
    cout<< "Index of element 0 on o2: " << binary_search(o2, 0)<<endl;
    cout<< "Index of element 93 on o3: " << binary_search(o3, 93)<<endl;
    cout<< "Index of element -42 on o1: " << binary_search(o1,-42)<<endl;

    vector<int> u1 = {1, 4, 8, 9, 10, 11, 12, 18, 21};
    vector<int> u2 = {1, 5, 8, 2, 3, -9, 19};
    vector<int> u3 = {42, 9, 1, 56, 2, 3, 78, 1, 0};
    
    cout<< "LINEAR SEARCH" <<endl;
    cout<< "Index of element 8 on u1: " << linear_search(u1, 8)<<endl;
    cout<< "Index of element 2 on u2: " << linear_search(u2, 2)<<endl;
    cout<< "Index of element 0 on u2: " << linear_search(u2, 0)<<endl;
    cout<< "Index of element 78 on u3: " << linear_search(u3, 78)<<endl;
    cout<< "Index of element 42 on u3: " << linear_search(u3,42)<<endl;
 
}