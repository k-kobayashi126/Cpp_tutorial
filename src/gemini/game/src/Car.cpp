#include <iostream>
#include <string>
#include "../include/Car.h"
using namespace std;

Car::Car(int startX, int startY){
    x = startX;
    y = startY;
}

int Car::getX() const {
    return x;
}

int Car::getY() const {
    return y;
}

void Car::moveLeft() {
    if (x > 0){
        x--;
    }
}

void Car::moveRight() {
    x++;
}

void Car::draw() const {
    cout << string(x, ' ') << "🚗" << endl;
}