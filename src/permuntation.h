#ifndef PERMUNTATION_H
#define PERMUNTATION_H
#include <iostream>
#include <QObject>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
class permuntation : public QObject
{
    Q_OBJECT
public:
    permuntation();
    std::string Print(int *a, int n);
    bool NextSet(int *a, int n);
    void swap(int *a, int i, int j);
    int num = 1; // номер перестановки
    int getProgressValue(int n);
    boost::multiprecision::cpp_bin_float_double value = 0;
};

#endif // PERMUNTATION_H
