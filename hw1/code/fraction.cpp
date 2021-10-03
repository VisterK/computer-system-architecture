
#include "fraction.h"

// Ввод параметров дробного числа из файла
void In(fraction &f, std::ifstream &ifst) {
    ifst >> f.a >> f.b;
}

// Случайный ввод параметров дробного числа
void InRnd(fraction &f) {
    f.a = Random();
    f.b = Random() + 1;
}

// Вывод параметров дробного числа в поток
void Out(fraction &f, std::ofstream &ofst) {
    ofst << "It is a fraction: Numerator = " << f.a << ", Imaginary = " << f.b
         << ". Converted to real = " << ConvertToReal(f) << "\n";
}

// Приведение числа к действительному
double ConvertToReal(fraction &f) {
    return ((double)f.a / (double)f.b);
}