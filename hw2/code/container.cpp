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


void Container::In(FILE* input = nullptr) {
    for (int i = 0; i < size; ++i) {
        int type;
        if(input == nullptr) {
            type = Random() % 3 + 1;
        }
        else{
            fscanf(input, "%d", &type);
        }
        if (type == 1) {
            Number* new_complex = new Complex();
            new_complex->CreateNumber(input);
            cont[i] = new_complex;
        }
        else if (type == 2) {
            Number* new_fraction = new Fraction();
            new_fraction->CreateNumber(input);
            cont[i] = new_fraction;
        }
        else if(type == 3) {
            Number* new_polar = new Polar();
            new_polar->CreateNumber(input);
            cont[i] = new_polar;
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