#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int score;
};

int main()
{
    Student s1;
    s1.name = "Taro";
    s1.score = 85;

    cout << "名前：" << s1.name << ", 点数：" << s1.score << endl;

    return 0;
}
