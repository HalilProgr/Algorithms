
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <typeinfo>
#include <algorithm>
#include <iostream>

// Binary_search

/*
 * Алгоритм бинарного поиска
 * рекурсивная реализация алгоритма
 */
template <class T>
bool binary_search(T* A, std::size_t begin, std::size_t end, T& value){
    if (end <= begin ) return false;

    std::size_t mid = begin + (end-begin)/2;

    if(mid == 0) return false;

    if(A[mid] > value)  return binary_search(A, begin, mid - 1, value);
    if(A[mid] < value)  return binary_search(A, mid + 1, end, value);
    if(A[mid] == value) return true;

    return false;
}


// Heap_sort

/*
 * функция для проверки состояния дерева на i узле.
 * n - размер дерева, i - узел который надо проверить на корректность, n - колличесвто верно расположенных элементов в пирамиде.
 */
template <class T>
void MaxHeapify(T* A, std::size_t i, std::size_t heapSize){
    std::size_t l = 2 * i;
    std::size_t r = 2 * i + 1;

    std::size_t largest;

    if (l < heapSize && A[l] > A[i]) largest = l;
    else largest = i;

    if (r < heapSize && A[r] > A[largest]) largest = r;

    if (largest != i){
        std::swap(A[i], A[largest]);
        MaxHeapify(A, largest, heapSize);
    }
};

/*
 * Инвариат цикла: в начале каждой итерации цикла for каждый узел i + 1, i + 2, i + 3 ... n
 * является корнем невозрастающей пирамиды
 */
template <class T>
void BuildMaxHeap(T* A, std::size_t n){
    for(std::size_t i = n/2; i > 0; i--) MaxHeapify(A, i, n);
    MaxHeapify(A, 0, n);
}

/*
 * Рабочая сортировка, при изменении условия сортировки необходимо заменить функцию Heapify. время работы алгоритма О(n*lg(n))
 */
template <class T>
void HeapSort(T* A, std::size_t n){
    BuildMaxHeap(A, n);

    for (std::size_t i = n - 1; i > 0; i--){
        std::swap(A[0], A[i]);
        MaxHeapify(A, 0, i);
    }
}


// Insertion_sort

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


// Merge_sort

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


// Quick_sort

// Быстрая сортировка
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

// Selection_sort

// Сортировка выбором
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


#endif // ALGORITHM_H
