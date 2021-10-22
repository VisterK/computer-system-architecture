#include "complex.h"


Complex::Complex(double a, double b) : a(a), b(b) {
}

//------------------------------------------------------------------------------
// Приведение к действительному виду
double Complex::ConvertToReal() {
    return std::sqrt(a * a + b * b);
}


void Complex::Print(FILE* out) {
    fprintf(out, "This is a polar number:\n"
                 "Real: %lf\n"
                 "Imaginary: %lf\n"
                 "Converted to real: %lf\n\n", a, b, ConvertToReal());
}