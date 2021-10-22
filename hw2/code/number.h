#ifndef HW2_NUMBER_H
#define HW2_NUMBER_H

#include "cstdlib"
#include "iostream"

//------------------------------------------------------------------------------
// number.h - содержит описание обобщающей число
//------------------------------------------------------------------------------



class Number {
public:
    virtual ~Number() = default;

    // Приведение к действительному числу
    virtual double ConvertToReal() = 0;
    virtual void Print(FILE *out) = 0;
    virtual void CreateNumber(FILE* input = nullptr) = 0;

};

//Number* CreateNumber(int type, FILE* input);

#endif //HW2_NUMBER_H
