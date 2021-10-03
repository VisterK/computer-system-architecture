#ifndef HW1_NUMBER_H
#define HW1_NUMBER_H

#include <fstream>

//------------------------------------------------------------------------------
// number.h - содержит описание обобщающей число
//------------------------------------------------------------------------------

#include "complex.h"
#include "fraction.h"
#include "polar.h"

struct number {
    enum key {
        COMPLEX,
        FRACTION,
        POLAR
    };
    key k;
    union{
        complex c;
        fraction f;
        polar p;
    };
};

// Ввод обобщенного числа
number* In(std::ifstream &ifdt);

// Случайный ввод обобщенного числа
number* InRnd();

// Вывод обобщенного числа
void Out(number &s, std::ofstream &ofst);

// Приведение к действительному числу
double ConvertToReal(number &s);


#endif //HW1_NUMBER_H
