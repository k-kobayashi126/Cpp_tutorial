#include <iostream>
using namespace std;

class Animal
{
    public:
        virtual void cry();
};

void Animal::cry(){
    cout << "..." << endl;
}

class Dog: public Animal
{
    public:
        void cry();
};

void Dog::cry(){
    cout << "ワンワン！" << endl;
}

class Cat: public Animal
{
    public:
        void cry();
};

void Cat::cry(){
    cout << "ニャー！" << endl;
}

int main()
{
    Animal* ptr1;
    Dog dog = Dog();
    ptr1 = &dog;

    ptr1->cry();

    Animal* ptr2;
    Cat cat = Cat();
    ptr2 = &cat;

    ptr2->cry();

    return 0;
}