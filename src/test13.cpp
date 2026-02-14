#include <iostream>
using namespace std;

class Person
{
    protected:
        int age = 0;
    public:
        Person(int age){
            this->age = age;
            cout << "Personのコンストラクタ" << endl;
        }
        virtual ~Person(){
            cout << "Personのデストラクタ" << endl;
        }
        virtual void showAge() = 0;
};

class Student: public Person
{
    public:
        Student(int age): Person(age){
            cout << "Studentのコンストラクタ" << endl;
        }
        ~Student(){
            cout << "Studentのデストラクタ" << endl;
        }
        void showAge() override {
            cout << "Student: " << age << endl;
        }
};

class Teacher: public Person
{
    public:
        Teacher(int age): Person(age){
            cout << "Teacherのコンストラクタ" << endl;
        }
        ~Teacher(){
            cout << "Teacherのデストラクタ" << endl;
        }
        void showAge() override {
            cout << "Teacher: " << age << endl;
        }
};

int main()
{
    Person* p1 = new Student(20);
    Person* p2 = new Teacher(35);

    p1->showAge();
    p2->showAge();

    delete p1;
    delete p2;

    return 0;
}