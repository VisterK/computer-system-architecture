#include "fraction.h"

Fraction::Fraction(): a(0), b(0){
}

Fraction::Fraction(int a, int b): a(a), b(b) {}


// Приведение числа к действительному
double Fraction::ConvertToReal() {
    return ((double)a / (double)b);
}

void Fraction::Print(FILE* out) {
    fprintf(out, "This is a polar number:\n"
                 "Numerator: %d\n"
                 "Denominator: %d\n"
                 "Converted to real: %lf\n\n", a, b, ConvertToReal());
}