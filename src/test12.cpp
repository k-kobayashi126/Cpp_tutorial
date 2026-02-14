#include <iostream>
using namespace std;

class Person
{
    protected:
        int age = 20;

    public: 
        Person(int age){
            cout << "基底クラスのコンストラクタ" << endl;
            this->age = age;
        }
        virtual ~Person(){
            cout << "基底クラスのデストラクタ" << endl;
        }
        virtual void showAge(){
            cout << "Person: " << this->age << endl;
        }
};

class Student: public Person
{
    public:
        Student(int age): Person(age){
            cout << "派生クラスのコンストラクタ" << endl;
        }
        ~Student(){
            cout << "派生クラスのデストラクタ" << endl;
        }
        void showAge() override {
            cout << "Student: " << this->age << endl;
        }
};

int main()
{
    Person* p = new Student(20);
    p->showAge();

    delete p;

    return 0;
}