/*********************
Name: Odelya Yaakowich
ID: 207346784
**********************/


#pragma once
#include "Animal.h"
#include <ctime>
#include <cstdlib>
#define ROWS 20
#define COLS 40

class Dog : public Animal {
    bool turn = false;
    int direction = 0;
    int steps;
public:
    Dog(const std::string& name, const Location& location):Animal(name, location) {};//ctor

    char getInitial() const override;

    void turnVertically() override;

    void turnHorizontally() override;

    void step() override;

    void printDetails() override;

    void move() override;

};


