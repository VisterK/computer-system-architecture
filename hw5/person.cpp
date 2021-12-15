#include <thread>
#include "person.h"
#include "hotel.h"
#include <iostream>


void Person::checkInto(Person& person, Hotel* hotel, std::ofstream& ofst) {
    while (true) {
        for(size_t i = 0; i < hotel->getSize(); ++i) {
            if(!hotel->rooms[i].getDays()) {
                hotel->rooms[i] = person;
                ofst << "Person " << person.name << " is in room #" << (i + 1) << std::endl;
                std::cout << "Person " << person.name << " is in room #" << (i + 1) << std::endl;
                return;
            }
        }
        std::this_thread::sleep_for (std::chrono::milliseconds (100));
    }
}
