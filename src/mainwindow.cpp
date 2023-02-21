/******библиотеки QT*******/
#include "mainwindow.h"
#include "ui_mainwindow.h"

/*****библиотеки Boost*****/
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/exception/to_string.hpp>
using namespace boost::multiprecision;

/**Стандартные библиотеки**/
#include <iostream>
using namespace std;

/*Прототипы функций*/
cpp_int boost_factorial(cpp_int num);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**Перестановки**/
cpp_int permutation(cpp_int n)
{
    /*   C = n!   */
    return boost_factorial(n);
}

/*Сочетания*/
cpp_int combination(cpp_int n, cpp_int m)
{
   /*    C = n!/m!*(n-m)!    */

    return (boost_factorial(n))/
            ((boost_factorial(m))*(boost_factorial(n-m)));
}

cpp_int partition(cpp_int n, cpp_int k)
{
    //в разработке
}

cpp_int boost_factorial(cpp_int num)
{
    cpp_int fact = 1;
    for (cpp_int i = num; i > 1; --i)
        fact *= i;
    return fact;
}

void MainWindow::on_pushButton_clicked()
{
    string str =ui->lineEdit->text().toStdString();
    cpp_int n(str);
    n = permutation(n);
    string result = n.str();
    ui->textBrowser->clear();
    ui->textBrowser->append(QString::fromStdString(result));
}


void MainWindow::on_pushButton_2_clicked()
{
    string str2 =ui->lineEdit_2->text().toStdString();
    string str3 =ui->lineEdit_3->text().toStdString();
    cpp_int n(str2);
    cpp_int m(str3);
    cpp_int result = combination(n,m);
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append(QString::fromStdString(result.str()));
}

