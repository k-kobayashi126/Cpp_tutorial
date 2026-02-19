#pragma once

class Obstacle
{
    private:
        int x, y;
    public:
        Obstacle(int startX, int startY);
        int getX() const;
        int getY() const;
        void moveDown();
        void draw() const;
        void resetPosition(int newX, int newY);
};