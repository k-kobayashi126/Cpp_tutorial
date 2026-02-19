#include <iostream>
using namespace std;

namespace MySpace {
    void greet(){
        cout << "Hello from MySpace!" << endl;
    }
}

int main()
{
    MySpace::greet();

    return 0;
}