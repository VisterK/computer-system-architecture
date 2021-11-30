//------------------------------------------------------------------------------
// inrnd.c - единица компиляции, вбирающая функции генерации случайных данных
//------------------------------------------------------------------------------

#include <stdlib.h>

int Random() {
    return rand() % 100 + 1;
}

void InRndComplex(void *r) {
    int x = Random();
    *((int*)r) = x;
    int y = Random();
    *((int*)(r+sizeof(int))) = y;
}

void InRndFraction(void *r) {
    int x = Random();
    *((int*)r) = x;
    int y = Random();
    *((int*)(r+sizeof(int))) = y;
}

void InRndPolar(void *r) {
    int x = Random();
    *((int*)r) = x;
    int y = Random();
    *((int*)(r+sizeof(int))) = y;

}

// Случайный ввод обобщенной фигуры
int InRndNumber(void *s) {
    int k = rand() % 3 + 1;
    switch(k) {
        case 1:
            *((int*)s) = 1;
            InRndComplex(s + sizeof(int));
            return 1;
        case 2:
            *((int*)s) = 2;
            InRndFraction(s + sizeof(int));
            return 1;
        case 3:
            *((int*)s) = 3;
            InRndPolar(s + sizeof(int));
            return 1;
        default:
            return 0;
    }
}

// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size) {
    void *tmp = c;
    while(*len < size) {
        if(InRndNumber(tmp)) {
            tmp = tmp + 3 * sizeof(int);
            (*len)++;
        }
    }
}
