#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <typeinfo>
// Алгоритм бинарного поиска

// рекурсивная реализация алгоритма

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

#endif // BINARY_SEARCH_H
