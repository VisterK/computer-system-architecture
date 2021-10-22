#ifndef HW2_CONTAINER_H
#define HW2_CONTAINER_H


#include "complex.h"
#include "fraction.h"
#include "polar.h"


// Контейнер на основе одномерного массива
class Container {
public:
    Container();
    ~Container();
    Container(int size);

    void In(FILE* in);
    //void InRnd();
    void Out(FILE* out);
    void Clear();

    enum{
        MAX_LENGTH = 10000
    };

    int size; // текущая длина
    Number** cont;

};

// Сортировка элементов контейнера методом Straight selection.
void sort(Container &c);

#endif //HW2_CONTAINER_H
