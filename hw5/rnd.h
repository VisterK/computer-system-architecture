#pragma once

#include <cstdlib>

// rnd.h - генератор случайных чисел в диапазоне от 0 до 100

inline int Random() {
    return rand() % 100;
}