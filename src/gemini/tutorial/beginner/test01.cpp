#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int age;
    
    cout << "名前を入力してください：";
    cin >> name;
    cout << "年齢を入力してください：";
    cin >> age;

    cout << "こんにちは、" << name << "さん。あなたは" << age << "歳ですね。" << endl;

    return 0;
}