#include <iostream>
using namespace std;

void swapFunc(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{
    int x = 10;
    int y = 20;
    swapFunc(&x, &y);
    cout << x << ", " << y << endl;

    return 0;
}