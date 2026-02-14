#include <iostream>
using namespace std;

class Student
{
    public:
        int num;
        int year;
        void show();
};

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