#include "complex.h"

// Ввод параметров комплексного числа из файла
void In(complex &c, std::ifstream &ifst) {
    ifst >> c.a >> c.b;
}

// Случайный ввод параметров комплексного числа
void InRnd(complex &c) {
    c.a = Random();
    c.b = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в форматируемый поток
void Out(complex &c, std::ofstream &ofst) {
    ofst << "It is Complex number: Real = " << c.a << ", Imaginary = " << c.b
         << ". Converted to real = " << ConvertToReal(c) << "\n";
}

//------------------------------------------------------------------------------
// Приведение к действительному виду
double ConvertToReal(complex &c) {
    return std::sqrt(c.a * c.a + c.b * c.b);
}