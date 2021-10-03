#ifndef HW1_CONTAINER_H
#define HW1_CONTAINER_H


#include "number.h"


// Контейнер на основе одномерного массива
struct container {
    enum{
        MAX_LENGTH = 10000
    };
    int len; // текущая длина
    number *cont[MAX_LENGTH];
};

// Инициализация контейнера
void Init(container &c);

// Освобождение памяти
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &ifst);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst);

// Сортировка элементов контейнера методом Straight selection.
void sort(container &c);

#endif //HW1_CONTAINER_H
