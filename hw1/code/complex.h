#ifndef HW1_COMPLEX_H
#define HW1_COMPLEX_H

#include <fstream>
#include "rnd.h"
#include <cmath>

struct complex {
    double a, b; // действительная и мнимая часть
};

// Ввод параметров комплексного числа из файла
void In(complex &c, std::ifstream &ifst);

// Случайный ввод параметров комплексного числа
void InRnd(complex &c);

// Вывод параметров комплексного числа в форматируемый поток
void Out(complex &c, std::ofstream &ofst);

// Приведение комплексного числа к действильному
double ConvertToReal(complex &c);


#endif //HW1_COMPLEX_H
