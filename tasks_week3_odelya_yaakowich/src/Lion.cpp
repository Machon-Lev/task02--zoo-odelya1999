/*********************
Name: Odelya Yaakowich
ID: 207346784
**********************/


#include "Lion.h"


void Lion::turnHorizontally() 
{

    switch (direction) {
    case left:
        direction = right;
        break;
    case right:
        direction = left;
        break;
    }
}

void Lion::step() 
{

    Location loc = getLocation();

    if (direction == left) {
        if (loc.getY() > 2) {
            loc.setY(loc.getY() - 2);
            setLocation(loc);
        }
        else if (loc.getY() == 2) {
            loc.setY(0);
            setLocation(loc);
            direction = right;
        }
        else
            direction = right;
    }
    else {
        if (loc.getY() < COLS - 3) {
            loc.setY(loc.getY() + 2);
            setLocation(loc);
        }

        else if (loc.getY() == COLS - 3) {
            loc.setY(COLS - 1);
            setLocation(loc);
            direction = left;
        }
        else
            direction = left;
    }
}

char Lion::getInitial() const 
{
    return 'L';
}

void Lion::printDetails() 
{
    std::cout << "Lion details:: name: " << getName() << " location: " << getLocation() << std::endl;
}




