//------------------------------------------------------------------------------
// input.c - единица компиляции, вбирающая в себя все функции ввода данных
//------------------------------------------------------------------------------

#include <stdio.h>


// Ввод параметров прямоугольника из файла
void InComplex(void *r, FILE *ifst) {
    fscanf(ifst, "%d%d", (int*)r, (int*)(r+sizeof(int)));
}

// Ввод параметров треугольника из файла
void InFraction(void *t, FILE *ifst) {
    fscanf(ifst, "%d%d", (int*)t,
           (int*)(t+sizeof(int)));
}

void InPolar(void *t, FILE *ifst) {
    fscanf(ifst, "%d%d", (int*)t,
           (int*)(t+sizeof(int)));
}

// Ввод параметров обобщенной фигуры из файла
int InNumber(void *s, FILE *ifst) {
    int k;
    fscanf(ifst, "%d", &k);
    switch(k) {
        case 1:
            *((int*)s) = 1;
            InComplex(s + sizeof(int), ifst);
            return 1;
        case 2:
            *((int*)s) = 2;
            InFraction(s + sizeof(int), ifst);
            return 1;
        case 3:
            *((int*)s) = 3;
            InPolar(s + sizeof(int), ifst);
            return 1;
        default:
            return 0;
    }
}

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst) {
    void *tmp = c;
    while(!feof(ifst)) {
        if(InNumber(tmp, ifst)) {
            tmp = tmp + 3 * sizeof(int);
            (*len)++;
        }
    }
}
