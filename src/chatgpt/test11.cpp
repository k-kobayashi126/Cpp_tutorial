#include <iostream>
using namespace std;

class Person
{
    private:
        int age = 0;
    
    public:
        Person(int age){
            this->age = age;
        }

        void showAge(){
            cout << this->age << endl;
        }
};

int main()
{
    Person person(20);
    person.showAge();

    return 0;
}