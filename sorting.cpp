#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_vec(vector<int> arr, string title){
    cout<<title<<endl;
    for (int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}


void merge(vector<int> &arr, int l, int m, int h){
    vector<int> arr_l (arr.begin() + l, arr.begin() + m + 1);
    vector<int> arr_h (arr.begin() + m + 1, arr.begin() + h + 1);
    int li = 0;
    int hi = 0;

    for (int i = l; i <= h; i++){
        
        if (li < arr_l.size() && (hi >= arr_h.size() || arr_l[li] < arr_h[hi])){
            arr[i] = arr_l[li];
            li++;
        } else {
            arr[i] = arr_h[hi];
            hi++;
        }
    }
    
}

void mergesort_aux(vector<int> &arr, int l, int h){
    
    if (l < h){
        int m = l + (h - l)/2;
        mergesort_aux(arr, l, m);
        mergesort_aux(arr, m+1, h);

        merge(arr, l, m, h);
    }
}


void mergesort(vector<int> &arr){
    mergesort_aux(arr, 0, arr.size() - 1);
}


int main(){
    vector<int> v1 = {4, 6, 2, 1, 6, 7, 2, 9, 10, -1, 0, 4, 6};
    vector<int> v2 = {4};
    vector<int> v3 = {4, 6, 2, 1, 6, 7, 2, 9, 10, -1, 0, 4, 6, 0, 0, 2, 4, 876, -13, 87, 23, 0, 14, -12};
    vector<int> v4 = {4, 2, 1, 6, 7, 9, 10, -1, 0};
    vector<int> v5 = {-1, -1, -1, 0, -1, -1, 2, -4};
    

    print_vec(v1, "Initial vector");
    mergesort(v1);
    print_vec(v1, "Final vector");

    print_vec(v2, "Initial vector");
    mergesort(v2);
    print_vec(v2, "Final vector");

    print_vec(v3, "Initial vector");
    mergesort(v3);
    print_vec(v3, "Final vector");

    print_vec(v4, "Initial vector");
    mergesort(v4);
    print_vec(v4, "Final vector");

    print_vec(v5, "Initial vector");
    mergesort(v5);
    print_vec(v5, "Final vector");

}