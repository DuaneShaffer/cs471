// assn01.h
// Duane Shaffer
// 6 September 2018
//
// For CS 471 Fall 2018
// Header file for quicksort algorithm
// Used in Assignment 1

#include <vector> 

template <typename RAIter>
RAIter my_partition(RAIter begin, RAIter end){
    auto pivot = *(end-1);
    auto i = begin;
    for (auto j = begin; j < end; ++j) {
        if (*j < pivot) {
            std::iter_swap(i, j);
            ++i;
        }
    }
    std::iter_swap(i, (end-1));
    return i;
}

template <typename RAIter>
void my_quicksort(RAIter begin, RAIter end){
    if (begin < end){
        RAIter p = my_partition(begin, end);
        my_quicksort(begin, p);
        my_quicksort(p+1, end);
    }
}
