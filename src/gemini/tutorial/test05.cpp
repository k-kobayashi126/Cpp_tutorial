#include <iostream>
using namespace std;

int getMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int n1, n2;
    cout << "一つ目の整数：";
    cin >> n1;
    cout << "二つ目の整数：";
    cin >> n2;

    cout << n1 << "と" << n2 << "で大きいは" << getMax(n1, n2) << "です" << endl;
    
    return 0;
}