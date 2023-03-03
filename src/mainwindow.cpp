/******библиотеки QT*******/
#include "mainwindow.h"
#include "ui_mainwindow.h"

/*****библиотеки Boost*****/
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/exception/to_string.hpp>
using namespace boost::multiprecision;

/**Стандартные библиотеки**/
#include <iostream>
#include <QThread>

/**классы*/
#include "combination.h"
#include "permuntation.h"
using namespace std;

/*Прототипы функций*/
cpp_int combination_quality(cpp_int n, cpp_int m);
string clening_str(string str);

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

//перестановки:
void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();   //очищаем браузер если были прощлые рассчёты

    permuntation pr;            //класс рассчёта перестановок

    QThread *qth = new QThread; //создание потока для последующего выноса в него же

    pr.moveToThread(qth);       //переносим в другой поток

    int n = ui->lineEdit->text().toInt();   //записываем количество чисел

    ui->textBrowser->append("N = " + ui->lineEdit->text());

    int *a = new int[n];

    string nums = ui->lineEdit_5->text().toStdString();

    nums = clening_str(nums);

    for (int i = 0; i < n; i++)
        a[i] = (int)nums[i] - '0';


    sort(a, a + n);

    ui->textBrowser->append(QString::fromStdString(pr.Print(a, n)));


    while (pr.NextSet(a, n))
    {
        ui->progressBar_2->setValue(pr.getProgressValue(n));
        ui->textBrowser->append(QString::fromStdString(pr.Print(a, n)));
    }
}


//сочетания
void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser_2->clear();   //очищаем браузер если были прощлые рассчёты

    combination cb;

    QThread *qth = new QThread;

    cb.moveToThread(qth);

    string str = ui->lineEdit_2->text().toStdString();   //записываем количество чисел

    str = clening_str(str);
    int n = str.size();

    int m = ui->lineEdit_3->text().toInt();   //записываем количество чисел

    int *a;
    a = new int[n];

    for (int i = 0; i < n; i++)
      a[i] = i+1;

    ui->textBrowser_2->append(QString::fromStdString(cb.Print(a, m,str)));
    if (n >= m)
      while (cb.NextSet(a, n, m))
      {
        ui->progressBar->setValue(cb.getProgressValue(n, m));

        ui->textBrowser_2->append(QString::fromStdString(cb.Print(a, m,str)));
      }

}

//разбиения
void MainWindow::on_pushButton_3_clicked()
{
    ui->textBrowser_3->append("n=");
        int n = 0;
        ui->textBrowser_3->clear();
        n = ui->lineEdit_4->text().toInt();
        //ui->progressBar->setValue(40);
        T_summands  summands;
        summands_partition(n, n, summands);
       // ui->progressBar->setValue(100);
}

//для вывода в textBorowser
void MainWindow::print_summands(int n_start, const T_summands&  summands)
{
    std::string str;
    str +=(std::to_string(n_start)+" = ");
    for(T_summands::const_iterator  summands_it = summands.begin(); summands_it != summands.end(); ++summands_it)
        str+=(std::to_string(*summands_it)) + (summands_it != summands.end() - 1 ? " + " : "\n");
    ui->textBrowser_3->append(QString::fromStdString(str));
}

void MainWindow::summands_partition(int n_start, int n_cur, const T_summands&  summands)
{
    if(!n_cur)
        print_summands(n_start, summands);

    for(int cur_slag = summands.empty() ? 1 : summands.back(); n_cur - cur_slag >= 0; ++cur_slag)
    {
        T_summands  summands_new(summands);
        summands_new.push_back(cur_slag);
        summands_partition(n_start, n_cur - cur_slag, summands_new);
    }
}

//функция очищает строку от пробелов
string clening_str(string str)
{
    string res;
    for(int i = 0; i < str.size();i++)
        if(str[i] != ' ') res += str[i];
    return res;
}
