#include <iostream>
using namespace std;

void doubleValue(int& ref) {
    ref *= 2;
}

int main()
{
    int num = 10;
    doubleValue(num);

    cout << "num: " << num << endl;

    return 0;
}