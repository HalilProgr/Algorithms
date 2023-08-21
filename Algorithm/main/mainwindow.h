#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <array>
#include <random>
#include <time.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


    // шаблонный указатель на функции сортировки. Все функции сортировки имеют
    // одинаковый интерфейс (данные, номер первого эллемента, номер последнего элемента)
    template <class T>
    using pSortFunct = void (*)(T* A, int begin, int end);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // void setSortFunction(); <- не уверен что нужно.

private:
    // По уму конечно анализ времени работы функций надо вынессти в отдельную функцию
    // и отдельный поток, пока сделаю в одном потоке.
    void plotGraph(int countStartEllement, int step, int countEndEllement);

    // функция заполнения данных случаными числами.
    template <class T>
    void generateRandom(std::vector<T> &A);

    Ui::MainWindow *ui;

private slots:

    // слот срабатываемый при нажатии кнопки, считывает значения полей, вызывает функцию plotGraph()
    void startAnalize(pSortFunct<class T> func){};
};

#endif // MAINWINDOW_H
