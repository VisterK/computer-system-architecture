#ifndef HW2_COMPLEX_H
#define HW2_COMPLEX_H


#include "number.h"
#include "rnd.h"
#include <cmath>

class Complex: public Number {
public:
    double a, b; // действительная и мнимая часть
    Complex();
    Complex(double a, double b);

    // Приведение комплексного числа к действильному
    double ConvertToReal() override;
    // Вывод числа
    void Print(FILE* out) override;
    // Создание числа
    void CreateNumber(FILE* input) override;
};

#endif //HW2_COMPLEX_H