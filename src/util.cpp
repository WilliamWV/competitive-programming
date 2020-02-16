#include "../include/util.h"

using namespace std;

template <typename T>
bool vectorCompare(vector<T> &v1, vector<T> &v2){
    if (v1.size() != v2.size()){
        return false;
    } 
    for (int i = 0; i < v1.size(); i++){
        if (v1[i] != v2[i]){ 
            return false;
        }
    }
    return true;
}


void print_vec(vector<int> arr, string title){
    cout<<title<<endl;
    for (int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void print_mat(std::vector<std::vector<int>> mat, std::string title){
    cout<<title<<endl;
    for(int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}