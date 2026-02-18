#include <iostream>
#include <string>
using namespace std;

template <typename T>
T getMax(T a, T b){
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    cout << getMax<int>(10, 20) << endl;
    cout << getMax<double>(1.5, 0.5) << endl;
    cout << getMax<string>("Apple", "Banana") << endl;

    return 0;
}