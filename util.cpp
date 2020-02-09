#include "util.h"

using namespace std;

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