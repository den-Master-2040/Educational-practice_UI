#include "combination.h"
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <algorithm>
using namespace boost::multiprecision;

using namespace std;
combination::combination(QObject *parent)
    : QObject{parent} {
}

cpp_bin_float_double boost_factorial(int num);
cpp_bin_float_double combination_quantity(cpp_bin_float_double n, cpp_bin_float_double m);

bool combination::NextSet(int *a, int n, int m)
{
  int k = m;
  for (int i = k - 1; i >= 0; --i)
    if (a[i] < n - k + i + 1)
    {
      ++a[i];
      for (int j = i + 1; j < k; ++j)
        a[j] = a[j - 1] + 1;
      return true;
    }
  return false;
}

string combination::Print(int *a, int n, std::string str)
{
  string res = (std::to_string(this->num++) + ": ");
  for (int i = 0; i < n; i++)
  {
    res += (char)(str[a[i]-1]);
    res += ' ';
  }
  return res;
}

int combination::getProgressValue(int n, int m)
{
    if(value.is_zero())
    {
        value = combination_quantity(n, m);
    }

    cpp_bin_float_double fl = num/value * 100;

    int result = fl.convert_to<int>();

    return result;
}



cpp_bin_float_double boost_factorial(cpp_bin_float_double num)
{
    cpp_bin_float_double fact(1);
    for (cpp_bin_float_double i = num; i > 1; --i)
        fact *= i;
    return fact;
}

/*Сочетания*/
cpp_bin_float_double combination_quantity(cpp_bin_float_double n, cpp_bin_float_double m)
{
   /*    C = n!/m!*(n-m)!    */

    return (boost_factorial(n))/
            ((boost_factorial(m))*(boost_factorial(n-m)));
}

