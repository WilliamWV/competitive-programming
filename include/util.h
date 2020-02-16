#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <string>

void print_vec(std::vector<int> arr, std::string title);
void print_mat(std::vector<std::vector<int>> mat, std::string title);

template <typename T>
bool vectorCompare(vector<T> &v1, vector<T> &v2);


#endif