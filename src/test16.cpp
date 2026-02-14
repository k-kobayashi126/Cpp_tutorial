#include <iostream>
using namespace std;

class NewClass
{
    public:
        void hello();
        void hello(string s);
};

void NewClass::hello(){
    cout << "HELLO" << endl;
}

void NewClass::hello(string s){
    cout << s << endl;
}

int main()
{
    NewClass obj = NewClass();
    obj.hello("asdfsdaf");

    return 0;
}
