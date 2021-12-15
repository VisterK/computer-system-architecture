#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "hotel.h"
#include "person.h"

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01\n"
                 "  Or:\n"
                 "     command -n number outfile01\n";
}


void decRooms(Hotel* hotel) {
    for (size_t i = 0; i < 1000; ++i) {
        for(size_t j = 0; j < hotel->getSize(); ++j) {
            hotel->rooms[j].decDays();
        }
        std::this_thread::sleep_for (std::chrono::milliseconds (300));
    }
}

void solve(Hotel* hotel, int size, std::ofstream& ofst) {
    for (int i = 0; i < size; ++i) {
        Person person = hotel->queue_.front();
        hotel->queue_.pop();
        std::this_thread::sleep_for (std::chrono::milliseconds (500));
        Person::checkInto(person, hotel, ofst);
    }
}


int main(int argc, char* argv[]) {

    Hotel* hotel = new Hotel();

    if(!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        int size;
        try {
            ifst >> size;
        } catch (std::exception& exception) {
            std::cout << "Wrong input" << std::endl;
            return 0;
        }
        hotel->in(size, ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            std::cout << "incorrect number of numbers = "
                      << size
                      << ". Set 0 < number <= 10000\n";
            return 3;
        }
        hotel->inRandom(size);
    }
    else {
        errMessage2();
        return 2;
    }

    std::ofstream out(argv[3]);


    std::thread th1(decRooms, hotel);
    std::thread th2(solve, hotel, hotel->queue_.size(), std::ref(out));

    th2.join();
    th1.detach();
}