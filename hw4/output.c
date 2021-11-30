//------------------------------------------------------------------------------
// output.c - единица компиляции, вбирающая в себя все функции вывода данных
//------------------------------------------------------------------------------

#include <stdio.h>

// Вычисление периметра прямоугольника
double ComplexToReal(void *r);

// Вывод параметров прямоугольника в файл
void OutComplex(void *r, FILE *ofst) {
    fprintf(ofst, "It is Complex: x = %d, y = %d.\n Converted to Real = %g\n",
            *((int*)r), *((int*)(r+sizeof(int))), ComplexToReal(r));
}

// Вычисление периметра треугольника
double FractionToReal(void *t);

// Вывод параметров треугольника в файл
void OutFraction(void *t, FILE *ofst) {
    fprintf(ofst, "It is Fraction: a = %d, b = %d.\n Converted to Real = %g\n",
            *((int*)t), *((int*)(t+sizeof(int))),
            FractionToReal(t));
}

double PolarToReal(void *t);

// Вывод параметров треугольника в файл
void OutPolar(void *t, FILE *ofst) {
    fprintf(ofst, "It is Polar: a = %d, b = %d.\n Converted to Real = %g\n",
            *((int*)t), *((int*)(t+sizeof(int))),
            PolarToReal(t));
}

// Вывод параметров текущей фигуры в файл
void OutNumber(void *s, FILE *ofst) {
    int k = *((int*)s);
    if(k == 1) {
        OutComplex(s + sizeof(int), ofst);
    }
    else if(k == 2) {
        OutFraction(s + sizeof(int), ofst);
    }
    else if (k == 3) {
        OutPolar(s + sizeof(int), ofst);
    }
    else {
        fprintf(ofst, "Incorrect figure!\n");
    }
}

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst) {
    void *tmp = c;
    fprintf(ofst, "Container contains %d elements.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i);
        OutNumber(tmp, ofst);
        fprintf(ofst, "\n");
        tmp = tmp + 3 * sizeof(int);
    }
}
