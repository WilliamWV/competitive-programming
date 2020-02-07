#include <iostream>
#include <vector>

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

int main(){
    vector<int> v1 = {1, 4, 8, 9, 10, 11, 12, 18, 21};
    vector<int> v2 = {0, 9, 192, 92830, 12723937, 128384621};
    vector<int> v3 = {1, 2, 8, 9, 17, 93};
    
    cout<< "Index of element 8 on v1: " << binary_search(v1, 8)<<endl;
    cout<< "Index of element 12 on v1: " << binary_search(v1, 12)<<endl;
    cout<< "Index of element 0 on v2: " << binary_search(v2, 0)<<endl;
    cout<< "Index of element 93 on v3: " << binary_search(v3, 93)<<endl;
    cout<< "Index of element -42 on v1: " << binary_search(v1,-42)<<endl;


}