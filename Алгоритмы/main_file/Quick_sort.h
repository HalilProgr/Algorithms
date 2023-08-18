
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <typeinfo>
#include <algorithm>

/*
 * БЛЯ РАБОТАЕТ! Очень быстрая сортировка (ВЖУХ и всё!)
 */

template <class T>
int Partition(T* A, std::size_t begin, std::size_t end){
    T reference = A[end - 1];
    int i = begin - 1;

    for (int j = begin; j < end - 1; j++){
        if (A[j] <= reference){
            i++;
            std::swap(A[i], A[j]);
        }
    }

    std::swap(A[i], A[end-1]);
    return i+1;
}

template <class T>
void QuickSort(T* A, std::size_t begin, std::size_t end){

    if (begin < end){
        int q = Partition(A, begin, end);

        QuickSort(A, begin, q);
        QuickSort(A, q+1, end);
    }
}

#endif // QUICK_SORT_H
