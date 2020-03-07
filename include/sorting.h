#ifndef SORTING_H
#define SORTING_H 

#include <iostream>
#include <vector>
#include <string>
#include "util.h"

void mergesort(std::vector<int> &arr);

void quicksort(std::vector<int> &arr);

void bubblesort(std::vector<int> &arr);

bool is_sorted(std::vector<int> &arr);

void sort(std::vector<int> &arr);

int insert_sorted_index(std::vector<int> &arr, int element);

void insert_sorted(std::vector<int> &arr, int element);

#endif