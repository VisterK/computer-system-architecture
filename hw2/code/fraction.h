#ifndef HW2_FRACTION_H
#define HW2_FRACTION_H

#include <iostream>
#include <fstream>

#include "rnd.h"
#include "number.h"

class Fraction: public Number {
public:

    Fraction();
    Fraction(int a, int b);

    int a, b; // числитель и знаменатель

    // Приведение дроби к действильному числу
    double ConvertToReal();
    void Print(FILE* out) override;
};


#endif //HW2_FRACTION_H
