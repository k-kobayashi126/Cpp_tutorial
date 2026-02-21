#include <iostream>
using namespace std;

class Vector2
{
    private:
        int x, y;
    public:
        Vector2(int x, int y);
        int getX() const;
        int getY() const;
        Vector2 operator+(const Vector2& other) const;
};

Vector2::Vector2(int x, int y){
    this->x = x;
    this->y = y;
}

int Vector2::getX() const{
    return this->x;
}

int Vector2::getY() const{
    return this->y;
}

// 参照渡し：引数のエイリアスになり、同じものを参照する
// 仮引数にconst修飾子：元データの変更の防止
Vector2 Vector2::operator+(const Vector2& other) const{
    // constが付いた仮引数で使用するメンバ関数はconstが付いたものだけ実行可能
    int x = this->x + other.getX();
    int y = this->y + other.getY();
    Vector2 result = Vector2(x, y);
    return result;
}

int main()
{
    Vector2 v1(1, 2);
    Vector2 v2(3, 4);
    Vector2 v3 = v1 + v2;

    cout << "v3の要素：x(" << v3.getX() << "), y(" << v3.getY() << ")" << endl;

    return 0;
}