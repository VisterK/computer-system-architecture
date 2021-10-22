#ifndef HW2_POLAR_H
#define HW2_POLAR_H

#include "number.h"
#include "rnd.h"

class Polar : public Number {
public:
    double phi; // угол
    double r; // радиус

    Polar();
    Polar(double, double);

    // Приведение полярного числа к действильному числу
    double ConvertToReal() override;
    void Print(FILE* out) override;
    void CreateNumber(FILE* input) override;

};


#endif //HW2_POLAR_H
