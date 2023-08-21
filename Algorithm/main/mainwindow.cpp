#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <algorithm>

#include <qcustomplot.h>

// включение h файлов с алгоритмами сортировки.

#include "Quick_sort.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    plotGraph(10, 50, 10000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::plotGraph(int countStartEllement, int step, int countEndEllement)
{
    QVector<double> X;
    QVector<double> Y;


    for (int i = countStartEllement; i < countEndEllement; i += step){
        std::vector<int> data(i);
        generateRandom<int>(data);

        clock_t start = clock();

        QuickSort<int>(data.data(), 0, data.size() - 1);

        clock_t end = clock();

        X.append(i);
        Y.append((double)(end - start) / CLOCKS_PER_SEC);
    }

    ui->centralwidget->addGraph();

    ui->centralwidget->graph(0)->setData(X, Y);

    //Подписываем оси Ox и Oy
    ui->centralwidget->xAxis->setLabel("x");
    ui->centralwidget->yAxis->setLabel("y");

    //Установим область, которая будет показываться на графике
    ui->centralwidget->xAxis->setRange(0, countEndEllement);//Для оси Ox

    ui->centralwidget->yAxis->setRange(0, *std::max_element(Y.constBegin(), Y.constEnd()));//Для оси Oy

    ui->centralwidget->replot();
}

template <class T>
void MainWindow::generateRandom(std::vector<T> &A)
{
    for (auto i : A){
        i = std::rand();
    }

}
