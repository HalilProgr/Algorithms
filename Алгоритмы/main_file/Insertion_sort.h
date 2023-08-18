#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include<typeinfo>

// Сортировка вставками

template <class T>
void insertion_sort(T* A, std::size_t n){
    for(std::size_t j = 1; j < n; j++){
        T key = A[j];
        std::size_t i = j - 1;
        while (i >= 0 && A[i] > key){
            A[i+1] = A[i];
            --i;
        }
        A[i+1] = key;
    }
}

#endif // INSERTION_SORT_H
