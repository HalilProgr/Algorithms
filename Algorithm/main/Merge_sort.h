#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <typeinfo>
#include <algorithm>

// Сортировка слиянием, наконец-то заработало, какой же ужас разбираться с этими индексами -_-

template <class T>
void merge(T* A, size_t p, size_t q, size_t r){

    size_t n1 = q-p+1;
    size_t n2 = r-q;

    T* L = new T[n1];
    T* R = new T[n2];

    for(size_t i = 0; i < n1; i++){
        L[i] = A[p+i];
    }

    for(size_t i = 0; i < n2; i++){
        R[i] = A[q+i+1];
    }

    size_t il = 0, ir = 0;
    size_t indexOfMergedArray = p;

    while (il < n1 && ir < n2) {
        if (L[il] <= R[ir]) {
            A[indexOfMergedArray] = L[il];
            il++;
        }
        else {
            A[indexOfMergedArray] = R[ir];
            ir++;
        }
        indexOfMergedArray++;
    }


    while (il < n1) {
        A[indexOfMergedArray] = L[il];
        il++;
        indexOfMergedArray++;
    }

    while (ir < n2) {
        A[indexOfMergedArray] = R[ir];
        ir++;
        indexOfMergedArray++;
    }

    delete[] L, R;
}

template <class T>
void merge_sort(T* A, size_t p, size_t r){
    if (p >= r)
        return;

    size_t q = p + (r-p)/2;

    merge_sort(A, p, q);
    merge_sort(A, q+1, r);

    merge(A,p,q,r);
}

#endif // MERGE_SORT_H
