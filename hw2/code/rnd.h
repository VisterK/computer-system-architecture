#ifndef HW2_RND_H
#define HW2_RND_H

#include <cstdlib>

// rnd.h - генератор случайных чисел в диапазоне от 0 до 100

inline int Random() {
    return rand() % 100;
}



#endif //HW2_RND_H
