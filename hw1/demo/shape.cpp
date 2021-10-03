//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "shape.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
bool In(ifstream &ifst, shape& s) {
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            s.k = shape::RECTANGLE;
            In(s.r, ifst);
            return true;
        case 2:
            s.k = shape::TRIANGLE;
            In(s.t, ifst);
            return true;
        default:
            return false;
    }
}

// Случайный ввод обобщенной фигуры
bool InRnd(shape& s) {
    auto k = rand() % 2 + 1;
    switch(k) {
        case 1:
            s.k = shape::RECTANGLE;
            InRnd(s.r);
            return true;
        case 2:
            s.k = shape::TRIANGLE;
            InRnd(s.t);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(shape &s, ofstream &ofst) {
    switch(s.k) {
        case shape::RECTANGLE:
            Out(s.r, ofst);
            break;
        case shape::TRIANGLE:
            Out(s.t, ofst);
            break;
        default:
            ofst << "Incorrect figure!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double Perimeter(shape &s) {
    switch(s.k) {
        case shape::RECTANGLE:
            return Perimeter(s.r);
            break;
        case shape::TRIANGLE:
            return Perimeter(s.t);
            break;
        default:
            return 0.0;
    }
}
