#ifndef HEAP_SORT_H
#define HEAP_SORT_H
// В данном файле представлены функции для работы с пирамидами.

#include <typeinfo>
#include <algorithm>
#include <iostream>

// функция для проверки состояния дерева на i узле.
// n - размер дерева, i - узел который надо проверить на корректность, n - колличесвто верно расположенных элементов в пирамиде.
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

#endif // HEAP_SORT_H
