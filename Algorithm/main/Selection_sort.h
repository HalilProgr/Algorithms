#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <typeinfo>
#include <algorithm>

template <class T>
void selection_sort(T* A, std::size_t n){
    for(std::size_t j = 0; j < n - 1;  j++){
        std::size_t min_pos;
        T min = A[j];

        for(std::size_t i = j+1; i < n; i++){
            if(min > A[i]){
                min = A[i];
                min_pos = i;
            }
        }

        if(min_pos != j){
            std::swap(A[j], A[min_pos]);
        }
    }
}

#endif // SELECTION_SORT_H
