#include <array>
#include <iostream>

#include <vector>
#include <utility>

//#include <QApplication>
//#include <mainwindow.h>

//#include "Selection_sort.h"
//#include "Merge_sort.h"
//#include "Binary_search.h"
//#include "Heap_sort.h"

//#include "Quick_sort.h"

// NOTE: Думаю стоит даваить в данный проект интересный объект для оценки скорости работы алгоритмов
// в зависимости от колличеста входных аргументов и построение графика результующее показатели алгоритма,
// для этого надо написать класс GUI с понятным интерфейсом (аргументом указаетль на функцию)


class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int max = 0;
        for(int i = 0; i < accounts.size(); i++){
            int temp = 0;
            for(int j = 0; j < accounts[i].size(); j++) temp+= accounts[i][j];
            if (temp > max) max = temp;
        }

        return max;
    }
};




int main(){

    int N = 5;


    std::vector<std::pair<int, int>> lines = {{1,2},{2,3},{4,5},{4,5},{5,6}};

    int n, minRline, minLline, count = 1;
    //for (int i = 0; i < N; i++) std::cin >> lines[i].first >> lines[i].second;

    minLline = lines[0].first;
    minRline = lines[0].second;

    for(int i = 1; i < lines.size(); i++){
        if(minLline < lines[i].second && minRline < lines[i].first){
            count++;
            minLline = lines[i].first;
            minRline = lines[i].second;
        }
    };
}


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




