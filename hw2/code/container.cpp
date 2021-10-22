#include "container.h"

Container::Container(){
    size = MAX_LENGTH;
    cont = new Number*[MAX_LENGTH];
}

Container::Container(int size_) : size(size_){
    size = size_;
    cont = new Number*[size];
}

Container::~Container(){
    for(int i = 0; i < size; ++i) {
        delete cont[i];
    }
    size = 0;
    delete[] cont;
}


void Container::In(FILE* input) {
    for (int i = 0; i < size; ++i) {
        int type;
        fscanf(input, "%d", &type);
        if (type == 1) {
            cont[i] = CreateNumber(0, input);
        }
        else if (type == 2) {
            cont[i] = CreateNumber(1, input);
        }
        else if(type == 3) {
            cont[i] = CreateNumber(2, input);
        }
    }
}


void Container::InRnd() {
    for (int i = 0; i < size; ++i) {
        int k = Random() % 3;
        if (k == 0) {
            cont[i] = CreateNumber(0, nullptr);
        }
        else if (k == 1) {
            cont[i] = CreateNumber(1, nullptr);
        }
        else if(k == 2) {
            cont[i] = CreateNumber(2, nullptr);
        }
    }
}

void Container::Out(FILE* out) {
    for(int i = 0; i < size; ++i) {
        cont[i]->Print(out);
    }
}


void Container::Clear() {
    for (int i = 0; i < size; i++) {
        delete cont[i];
    }
    size = 0;
    delete[] cont;
}

// Сортировка контейнера методом Straight Selection
void sort(Container &c) {
    int i = 0;
    int k = 0;
    Number *temp = nullptr;
    while (i < c.size) {
        k = i;
        for (int j = i + 1; j < c.size; j++) {
            if (c.cont[j]->ConvertToReal() <= c.cont[k]->ConvertToReal()) {
                k = j;
            }
        }
        temp = c.cont[i];
        c.cont[i] = c.cont[k];
        c.cont[k] = temp;
        i++;
    }
}