#include <iostream>
#include "test15.h"
using namespace std;

void Student::show(){
    cout << num << endl;
    cout << year << endl;
}

int main()
{
    Student Tarou;
    Tarou.num = 10;
    Tarou.year = 3;
    Tarou.show();

    return 0;
}