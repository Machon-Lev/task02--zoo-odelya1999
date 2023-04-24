/*********************
Name: Odelya Yaakowich
ID: 207346784
**********************/


#pragma once
#include <iostream>
struct Location {
    int x;
    int y;

    void setX(int _x) {
        x = _x;
    }

    void setY(int _y) {
        y = _y;
    }

    void setLocation(int _x, int _y) {
        setX(_x);
        setY(_y);
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Location& location) {
        os << "x: " << location.getX() << " y: " << location.getY();
        return os;
    }

    Location& operator+=(Location location) {
        x += location.x;
        y += location.y;
        return *this;
    }

    bool operator==(Location location) const {
        if (x != location.x or y != location.y)
            return false;
        return true;
    }

    bool operator!=(Location location) const {
        if (*this != location)
            return true;
        return false;
    }

    Location& operator=(Location location) {
        setLocation(location.getX(), location.getY());
        return *this;
    }

};


