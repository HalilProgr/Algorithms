
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <typeinfo>
#include <algorithm>


#include <iostream>
/*
 * БЛЯ РАБОТАЕТ! Очень быстрая сортировка (ВЖУХ и всё!)
 */

template <class T>
int Partition(T* A, int begin, int end){
    T reference = A[end];
    int i = begin - 1;

    for (int j = begin; j < end; j++){
        if (A[j] <= reference){
            i++;
            std::swap(A[i], A[j]);
        }
    }

    std::swap(A[i + 1], A[end]);
    return (i + 1);
}

template <class T>
void QuickSort(T* A, int begin, int end){

    if (begin < end){
        int q = Partition(A, begin, end);

        QuickSort(A, begin, q - 1);
        QuickSort(A, q + 1, end);
    }
}

#endif // QUICK_SORT_H
