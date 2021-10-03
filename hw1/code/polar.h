#ifndef HW1_POLAR_H
#define HW1_POLAR_H


#include <fstream>
#include "rnd.h"

struct polar {
    double phi; // угол
    double r; // радиус
};

// Ввод параметров полярного числа из файла
void In(polar &p, std::ifstream &ifst);

// Случайный ввод параметров полярного числа
void InRnd(polar &p);

// Вывод параметров полярного числа в форматируемый поток
void Out(polar &p, std::ofstream &ofst);

// Приведение полярного числа к действильному числу
double ConvertToReal(polar &p);

#endif //HW1_POLAR_H
