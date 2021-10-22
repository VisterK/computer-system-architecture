#include "polar.h"

Polar::Polar() : phi(0), r(0){
}

Polar::Polar(double phi, double r) : phi(phi), r(r) {
}

//------------------------------------------------------------------------------
// Приведение числа к действительному
double Polar::ConvertToReal() {
    return r;
}

void Polar::CreateNumber(FILE* input = nullptr){
    if (input == nullptr) {
        phi = Random();
        r = Random();
    }
    else {
        fscanf(input, "%lf %lf\n", &phi, &r);
    }
}

void Polar::Print(FILE* out) {
    fprintf(out, "This is a polar number:\n"
                 "angle: %lf\n"
                 "radius: %lf\n"
                 "Converted to real: %lf\n\n", phi, r, ConvertToReal());
}