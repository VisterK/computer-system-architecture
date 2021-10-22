#include "fraction.h"

Fraction::Fraction(): a(0), b(1){
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

void Fraction::CreateNumber(FILE* input) {
    if (input == nullptr) {
        a = Random();
        b = Random();
    }
    else {
        fscanf(input, "%d %d\n", &a, &b);
    }
}