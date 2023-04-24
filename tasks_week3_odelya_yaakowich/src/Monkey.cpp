/*********************
Name: Odelya Yaakowich
ID: 207346784
**********************/


#include "Monkey.h"

char Monkey::getInitial() const 
{
    return 'M';
}

void Monkey::turnVertically() 
{
    switch (direction) {
    case down:
        direction = up;
        break;
    case up:
        direction = down;
        break;
    }
}

void Monkey::turnHorizontally() 
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

void Monkey::step() 
{
    if (turn == 4) {
        turn = 0;
        srand((unsigned)time(NULL));
        direction = static_cast<int>(rand() % 4);

        srand((unsigned)time(NULL));
        steps = static_cast<int>(rand() % 2) + 1;
    }

    Location loc = getLocation();

    switch (direction) {
    case left:
        if (loc.getY() - steps > 0) {
            loc.setY(loc.getY() - steps);
            setLocation(loc);
        }
        else if (loc.getY() - steps == 0) {
            loc.setY(0);
            turnHorizontally();
            setLocation(loc);
        }
        else {
            turnHorizontally();
            if (steps == 1) {
                loc.setY(1);
                setLocation(loc);
            }
        }
        break;
    case right:
        if (loc.getY() + steps < 39) {
            loc.setY(loc.getY() + steps);
            setLocation(loc);
        }
        else if (loc.getY() + steps == 39) {
            loc.setY(39);
            turnHorizontally();
            setLocation(loc);
        }
        else
        {
            turnHorizontally();
            if (steps == 1) {
                loc.setY(38);
                setLocation(loc);
            }
        }
        break;
    case up:
        if (loc.getX() - steps > 0)
        {
            loc.setX(loc.getX() - steps);
            setLocation(loc);
        }
        else if (loc.getX() - steps == 0) {
            loc.setX(0);
            turnVertically();
            setLocation(loc);
        }
        else
        {
            turnVertically();
            if (steps == 1)
            {
                loc.setX(1);
                setLocation(loc);
            }
        }
        break;
    case down:
        if (loc.getX() + steps < 19)
        {
            loc.setX(loc.getX() + steps);
            setLocation(loc);
        }
        else if (loc.getX() + steps == 19) {
            loc.setX(19);
            turnVertically();
            setLocation(loc);
        }
        else
        {
            turnVertically();
            if (steps == 1)
            {
                loc.setX(18);
                setLocation(loc);
            }
        }
        break;
    }
    turn++;
}

void Monkey::printDetails() 
{
    std::cout << "Monkey details:: name: " << getName() << " location: " << getLocation() << std::endl;
}


