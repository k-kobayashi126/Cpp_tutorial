#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include  "../include/Obstacle.h"
using namespace std;

Obstacle::Obstacle(int startX, int startY) {
    x = startX;
    y = startY;
}

int Obstacle::getX() const {
    return this->x;
}

int Obstacle::getY() const {
    return this->y;
}

void Obstacle::moveDown() {
    if (rand()%2 == 0) {
        x++;
    } else {
        if (x > 0){
            x--;
        }
    }
    y++;
}

void Obstacle::draw() const {
    cout << string(x, ' ') << "💣" << endl;
}

void Obstacle::resetPosition(int newX, int newY) {
    x = newX;
    y = newY;
}