#include <array>
#include <iostream>

//#include "Selection_sort.h"
//#include "Merge_sort.h"
//#include "Binary_search.h"
//#include "Heap_sort.h"

#include "Quick_sort.h"

// NOTE: Думаю стоит даваить в данный проект интересный объект для оценки скорости работы алгоритмов
// в зависимости от колличеста входных аргументов и построение графика результующее показатели алгоритма,
// для этого надо написать класс GUI с понятным интерфейсом (аргументом указаетль на функцию)


int main(int argc, char *argv[])
{
    std::array<int, 8> a = {2, 8, 7, 1, 3, 5, 6, 4};

    //HeapSort(a.data(), a.size());

    QuickSort(a.data(), 0, a.size());

    std:: cout << "A: ";
    for(auto & t : a){
        std::cout << t << " ";
    }
    std::cout << std::endl;

/*
    for(auto & t : a){
        t = std::rand()%100;
    }

    std::sort(a.begin(),a.end());

    std:: cout << "A: ";
    for(auto & t : a){
        std::cout << t << " ";
    }
    std::cout << std::endl;

    int temp = 101;
    std::size_t t = 1;



    std::cout << t-1 << std::endl;

    if(binary_search(a.data(), 0, a.size(), temp))
        std::cout << temp << " finded in A" << std::endl;
    else
        std::cout << temp << " did not find in A" << std::endl;
    // merge(a.data(), 0, a.size()/2, a.size() );
    // merge_sort(a.data(), 0, a.size());

    // selection_sort(a.data(), a.size());

    //for(auto & t : a){
    //    std::cout << t << " ";
    //}

    //std::cout << std::endl;
*/
}


