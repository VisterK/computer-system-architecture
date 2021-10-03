#include "number.h"

// Ввод обобщенного числа
number* In(std::ifstream &ifst) {
    int k;
    number* num;
    ifst >> k;
    switch(k) {
        case 1:
            num = new number;
            num->k = number::COMPLEX;
            In(num->c, ifst);
            return num;
        case 2:
            num = new number;
            num->k = number::FRACTION;
            In(num->f, ifst);
            return num;
        case 3:
            num = new number;
            num->k = number::POLAR;
            In(num->p, ifst);
            return num;
        default:
            return nullptr;
    }
}

// Случайный ввод обобщенного числа
number* InRnd() {
    int k = rand() % 3 + 1;
    number* num;
    switch(k) {
        case 1:
            num = new number;
            num->k = number::COMPLEX;
            InRnd(num->c);
            return num;
        case 2:;
            num = new number;
            num->k = number::FRACTION;
            InRnd(num->f);
            return num;
        case 3:
            num = new number;
            num->k = number::POLAR;
            InRnd(num->p);
            return num;
        default:
            return nullptr;
    }
}

// Вывод обобщенного числа в поток
void Out(number &n, std::ofstream &ofst) {
    switch(n.k) {
        case number::COMPLEX:
            Out(n.c, ofst);
            break;
        case number::FRACTION:
            Out(n.f, ofst);
            break;
        case number::POLAR:
            Out(n.p, ofst);
            break;
        default:
            ofst << "Incorrect number!" << std::endl;
    }
}

// Приведение к действительному числу
double ConvertToReal(number &n) {
    switch(n.k) {
        case number::COMPLEX:
            return ConvertToReal(n.c);
        case number::FRACTION:
            return ConvertToReal(n.f);
        case number::POLAR:
            return ConvertToReal(n.p);
        default:
            return 0.0;
    }
}