#pragma once

#include "person.h"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include "rnd.h"

class Hotel {
private:
    size_t hotel_size = 30;
public:
    Person* rooms;
    std::queue<Person> queue_;

    Hotel() {
        hotel_size = 30;
        rooms = new Person[hotel_size];

        for (size_t i = 0; i < hotel_size; ++i) {
            rooms[i] = Person("", 0);
        }
    }


    size_t getSize() {
        return hotel_size;
    }

    void in(int size, std::ifstream& ifst) {
        for (size_t i = 0; i < size; ++i) {
            std::string name;
            int number_of_days;
            ifst >> name >> number_of_days;
            queue_.push(Person(name, number_of_days));
        }
    }

    void inRandom(int size) {
        for (size_t i = 0; i < size; ++i) {
            std::string name = "id" + std::to_string(i + 1);
            int number_of_days = Random();
            queue_.push(Person(name, number_of_days));
        }
    }

    void out(std::ofstream& ofst) {
        ofst << "All people left hotel" << std::endl;
    }




};