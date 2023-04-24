/*********************
Name: Odelya Yaakowich
ID: 207346784
**********************/


#pragma once
#include <iostream>
#include <utility>
#include "Location.h"

#define left  0
#define right  1
#define up  2
#define down  3

class Animal {
    std::string name;
    Location location;
    bool is_move;
    int direction;

public:

    Animal(const std::string& name, const Location& location) : name(name), location(location), is_move(true) {} //ctor

    virtual void printDetails() = 0; //print the details of each animal

    virtual char getInitial() const = 0; //returns the first char of class's name

    virtual const Location getLocation()//returns animal's location
    {
        return location;
    } 

    virtual void setLocation(const Location& _location)
    {
        Animal::location = _location;
    }

    virtual void step() = 0;//Causes the animal to advance a step, provided it is in motion

    virtual void stop() //causes the animal to stop
    {
        is_move = false;
    }

    virtual void move() //causes the animal to start moving
    {
        is_move = true;
    }

    virtual void turnVertically() = 0; //Causes the animal to change direction vertically

    virtual void turnHorizontally() = 0; //Causes the animal to change direction horizontally

    const std::string& getName() const 
    {
        return name;
    }

    virtual void setName(const std::string& _name)
    {
        Animal::name = _name;
    }


    friend std::ostream& operator<<(std::ostream& os, const Animal& animal)
    {
        os << "name: " << animal.name << " location: " << animal.location;
        return os;
    }
};


