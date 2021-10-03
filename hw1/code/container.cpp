#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

// Освобождение памяти
void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

void In(container &c, std::ifstream &ifst) {
    while (!ifst.eof()) {
        if ((c.cont[c.len] = In(ifst)) != nullptr) {
            c.len++;
        }
    }
}

void InRnd(container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}
//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " numbers.\n";
    for (int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

// Сортировка контейнера методом Straight Selection
void sort(container &c) {
    int i = 0;
    int k = 0;
    number *temp;
    while (i < c.len) {
        k = i;
        for (int j = i + 1; j < c.len; j++) {
            if (ConvertToReal(*c.cont[j]) <= ConvertToReal(*c.cont[k])) {
                k = j;
            }
        }
        temp = c.cont[i];
        c.cont[i] = c.cont[k];
        c.cont[k] = temp;
        i++;
    }
}