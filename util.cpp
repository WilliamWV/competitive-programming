#include "util.h"

using namespace std;

void print_vec(vector<int> arr, string title){
    cout<<title<<endl;
    for (int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}