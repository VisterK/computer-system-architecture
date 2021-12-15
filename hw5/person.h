#pragma once

#include <string>
#include <thread>
#include <mutex>



class Hotel;

class Person {
private:
    std::string name;
    size_t days;
public:

    Person() {
        name = "";
        days = 0;
    }

    Person(const std::string& name_, size_t days_) {
        name = name_;
        days = days_;
    }

    void setName(std::string& name_) {
        name = name_;
    }
    std::string getName() {
        return name;
    }

    size_t getDays() {
        return days;
    }

    void decDays() {
        days = (days > 0 ? days - 1 : 0);
    }

    static void checkInto(Person&, Hotel*,std::ofstream&);


};