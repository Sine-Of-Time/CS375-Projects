#ifndef MERGE_SORT_H // Include guard to prevent multiple inclusions
#define MERGE_SORT_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

// Function prototypes 
void mergeSort(std::vector<int>& arr, int low, int high);
void merge(std::vector<int>& arr, int low, int mid, int high);

#endif // MERGE_SORT_H