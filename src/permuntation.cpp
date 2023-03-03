#include "permuntation.h"
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <algorithm>
using namespace boost::multiprecision;
cpp_bin_float_double combination_quantity(cpp_bin_float_double num);
permuntation::permuntation()
{

}
void permuntation::swap(int *a, int i, int j)
{
  int s = a[i];
  a[i] = a[j];
  a[j] = s;
}
bool permuntation::NextSet(int *a, int n)
{
  int j = n - 2;
  while (j != -1 && a[j] >= a[j + 1]) j--;
  if (j == -1)
    return false; // больше перестановок нет
  int k = n - 1;
  while (a[j] >= a[k]) k--;

  swap(a, j, k);

  int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности

  while (l < r)
    swap(a, l++, r--);
  return true;
}
std::string permuntation::Print(int *a, int n)  // вывод перестановки
{

  std::string str =(std::to_string(num++) + ": ");
  for (int i = 0; i < n; i++)
  {
    str +=(((char)(a[i]+'0')));
    str += ' ';
  }
  return str;

}

int permuntation::getProgressValue(int n)
{
    if(value.is_zero())
    {
        value = combination_quantity(n);
    }

    boost::multiprecision::cpp_bin_float_double fl = num/value * 100;

    int result = fl.convert_to<int>();

    return result;
}

cpp_bin_float_double combination_quantity(cpp_bin_float_double num)
{
    cpp_bin_float_double fact(1);
    for (cpp_bin_float_double i = num; i > 1; --i)
        fact *= i;
    return fact;
}
