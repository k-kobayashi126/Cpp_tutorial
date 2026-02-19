#pragma once

class Car
{
    private:
        int x;
        int y;
    public:
        Car(int startX, int startY);
        int getX() const;
        int getY() const;
        void moveLeft();
        void moveRight();
        void draw() const;
};