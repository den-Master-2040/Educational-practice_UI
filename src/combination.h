#ifndef COMBINATION_H
#define COMBINATION_H

#include <QObject>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>

using namespace boost::multiprecision;

class combination : public QObject
{
    Q_OBJECT
public:
    int general(int n, int m);
    bool NextSet(int *a, int n, int m);
    std::string Print(int *a, int n, std::string str);
    int getProgressValue(int n, int m);
    cpp_bin_float_double value = 0;
    int num = 1;
    explicit combination(QObject *parent = nullptr);

signals:

};

#endif // COMBINATION_H
