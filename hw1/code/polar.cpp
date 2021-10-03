#include "polar.h"

// Ввод параметров полярного числа из файла
void In(polar &p, std::ifstream &ifst) {
    ifst >> p.phi >> p.r;
}

// Случайный ввод параметров полярного числа
void InRnd(polar &p) {
    p.phi = Random();
    p.r = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров полярного числа в форматируемый поток
void Out(polar &p, std::ofstream &ofst) {
    ofst << "It is a polar number: Angle = " << p.phi << ", Radius = " << p.r
         << ". Converted to real = " << ConvertToReal(p) << "\n";
}

//------------------------------------------------------------------------------
// Приведение числа к действительному
double ConvertToReal(polar &p) {
    return p.r;
}