#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <string>

void print_vec(std::vector<int> arr, std::string title);
void print_mat(std::vector<std::vector<int>> mat, std::string title);

template <typename T>
bool vectorCompare(std::vector<T> &v1, std::vector<T> &v2){
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


#endif