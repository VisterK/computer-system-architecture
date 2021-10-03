#ifndef HW1_FRACTION_H
#define HW1_FRACTION_H

#include <fstream>
#include "rnd.h"

struct fraction {
    int a, b; // числитель и знаменатель
};

// Ввод параметров дробного числа из файла
void In(fraction &f, std::ifstream &ifst);

// Случайный ввод параметров дробного числа
void InRnd(fraction &f);

// Вывод параметров дробного числа в поток
void Out(fraction &f, std::ofstream &ofst);

// Приведение дроби к действильному числу
double ConvertToReal(fraction &f);


#endif //HW1_FRACTION_H
