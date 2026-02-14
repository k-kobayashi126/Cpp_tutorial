#include <iostream>
using namespace std;

class Person
{
    private:
        int age = 0;
    public:
        void setAge(int age){
            this->age = age;
        }

        int getAge() const{
            return this->age;
        }

        void showAge() {
            cout << age << endl;
        }
};

int main()
{
    Person person;
    person.setAge(20);
    person.showAge();
    cout << person.getAge() << endl;

    return 0;
}
