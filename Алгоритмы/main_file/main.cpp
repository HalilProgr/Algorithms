#include <array>
#include <iostream>

//#include "Selection_sort.h"
#include "Merge_sort.h"

// NOTE: Думаю стоит даваить в данный проект интересный объект для оценки скорости работы алгоритмов
// в зависимости от колличеста входных аргументов и построение графика результующее показатели алгоритма,
// для этого надо написать класс GUI с понятным интерфейсом (аргументом указаетль на функцию)


int main(int argc, char *argv[])
{
    std::array<int, 7> a;


    for(auto & t : a){
        t = std::rand()%100;
    }

    for(auto & t : a){
        std::cout << t << " ";
    }
    std::cout << std::endl;

    //merge(a.data(), 0, a.size()/2, a.size() );
    merge_sort(a.data(), 0, a.size());

    //selection_sort(a.data(), a.size());

    for(auto & t : a){
        std::cout << t << " ";
    }

    std::cout << std::endl;

}


