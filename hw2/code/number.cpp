#include "number.h"
#include "complex.h"
#include "fraction.h"
#include "polar.h"

Number* CreateNumber(int type, FILE* input) {
    if(type == 0) {
        double a = 0, b = 0;
        if (input == nullptr) {
            a = Random();
            b = Random();
        }
        else {
            fscanf(input, "%lf %lf\n", &a, &b);
        }
        return new Complex(a, b);
    }
    else if (type == 1) {
        int a = 0, b = 0;
        if (input == nullptr) {
            a = Random();
            b = Random();
        }
        else {
            fscanf(input, "%d %d\n", &a, &b);
        }
        return new Fraction(a, b);
    }
    else if (type == 2) {
        double phi = 0, r = 0;
        if (input == nullptr) {
            phi = Random();
            r = Random();
        }
        else {
            fscanf(input, "%lf %lf\n", &phi, &r);
        }
        return new Polar(phi, r);
    }
    else {
        return nullptr;
    }
}