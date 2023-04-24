/*********************
Name: Odelya Yaakowich
ID: 207346784
**********************/


#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include "Animal.h"
#include "Lion.h"
#include "Monkey.h"
#include "Dog.h"

#define ROWS 20
#define COLS 40

class Zoo {
    std::vector<std::unique_ptr<Animal>> animals;
    void stop(int index);
    void move(int index);
    void create(char, std::string);
    void del(int index);
    void delAll(char type);
    void help();
    void step();
    void print_map();
    void print_list();
public:
    void run();
};



