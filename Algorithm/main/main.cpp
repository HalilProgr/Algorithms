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

/*
 * [["7", ".", ".", ".", "4", ".", ".", ".", "."],
 *  [".", ".", ".", "8", "6", "5", ".", ".", "."],
 *  [".", "1", ".", "2", ".", ".", ".", ".", "."],
 *  [".", ".", ".", ".", ".", "9", ".", ".", "."],
 *  [".", ".", ".", ".", "5", ".", "5", ".", "."],
 *  [".", ".", ".", ".", ".", ".", ".", ".", "."],
 *  [".", ".", ".", ".", ".", ".", "2", ".", "."],
 *  [".", ".", ".", ".", ".", ".", ".", ".", "."],
 *  [".", ".", ".", ".", ".", ".", ".", ".", "."]]
*/
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        int n = board.size();

        std::array<bool, 9> arrayStatus;

        //init mass

        for(int i = 0; i < n; i++) arrayStatus[i] = false;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    int temp = (board[i][j] - '0') - 1;
                    if(arrayStatus[temp] == true) return false;
                    arrayStatus[temp] = true;
                }
            }

            for(int i = 0; i < n; i++) arrayStatus[i] = false;
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[j][i] != '.'){
                    if(arrayStatus[int(board[j][i] - '0') - 1] == true) return false;
                    arrayStatus[int(board[j][i] - '0') - 1] = true;
                }
            }

            for(int i = 0; i < n; i++) arrayStatus[i] = false;
        }

        int offsetX = 0;
        int offsetY = 0;

        //так блять i - строчки (ось Y)
        //j - столбцы (ось X)

        //Вот эту хрень надо повторить 9!!! раз!!!

        // k - кол-во квадратиков
        for(int k = 0; k < n; k++){

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(board[offsetY + i][offsetX + j] != '.'){
                        if(arrayStatus[int(board[offsetY + i][offsetX + j] - '0') - 1] == true) return false;
                        arrayStatus[int(board[offsetY + i][offsetX + j] - '0') - 1] = true;
                    }
                }
            }

            for(int i = 0; i < n; i++) arrayStatus[i] = false;

            if(offsetX < 6) offsetX += 3;
            else{
                offsetX = 0;
                offsetY += 3;
            }

        }

        return true;
    }
};

int main(){
    std::vector<std::vector<char>> board ={{ '7', '.', '.', '.', '4', '.', '.', '.', '.'},
                                           { '.', '.', '.', '8', '6', '5', '.', '.', '.'},
                                           { '.', '1', '.', '2', '.', '.', '.', '.', '.'},
                                           { '.', '.', '.', '.', '.', '9', '.', '.', '.'},
                                           { '.', '.', '.', '.', '5', '.', '5', '.', '.'},
                                           { '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                           { '.', '.', '.', '.', '.', '.', '2', '.', '.'},
                                           { '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                           { '.', '.', '.', '.', '.', '.', '.', '.', '.'}};


    Solution s1;

    std::cout << s1.isValidSudoku(board);
}


/*
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




bool compare(std::pair<int, int>& lhs, std::pair<int, int>& rhs){
    return lhs.second < rhs.second;
}

int main(){

    int N = 5;


    std::vector<std::pair<int, int>> lines = {{1,2},{2,3},{4,5},{4,5},{5,6}};

    int n, minRline, minLline, count = 1;
    for (int i = 0; i < N; i++) std::cin >> lines[i].first >> lines[i].second;

    std::sort(lines.begin(), lines.end(), compare);

    minLline = lines[0].first;
    minRline = lines[0].second;

    for(int i = 1; i < lines.size(); i++){
        if(minLline < lines[i].first && minRline < lines[i].second){
            count++;
            minLline = lines[i].first;
            minRline = lines[i].second;

            std::cout << minLline << " " << minRline << std::endl;
        }
    };
}

*/
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




