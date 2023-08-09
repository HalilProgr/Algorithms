#include <array>
#include <iostream>

#include "Selection_sort.h"

// NOTE: Думаю стоит даваить в данный проект интересный объект для оценки скорости работы алгоритмов
// в зависимости от колличеста входных аргументов и построение графика результующее показатели алгоритма,
// для этого надо написать класс GUI с понятным интерфейсом (аргументом указаетль на функцию)

int main(int argc, char *argv[])
{
    std::array<int, 10> a;

    for(auto & t : a){
        t = std::rand()%100;
    }

    for(auto & t : a){
        std::cout << t << " ";
    }
    std::cout << std::endl;

    selection_sort(a.data(), a.size());

    for(auto & t : a){
        std::cout << t << " ";
    }
    std::cout << std::endl;
}


