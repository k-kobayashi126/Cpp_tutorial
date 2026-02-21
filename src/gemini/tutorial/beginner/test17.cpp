#include <iostream>
#include <string>
using namespace std;

double divFunc(int a, int b) {
    if (b != 0) {
        return double(a)/b;
    } else {
        throw "0では割れません！";
    }
}

int main()
{
    try{
        cout << divFunc(20, 4) << endl;
        cout << divFunc(20, 0) << endl;
    } catch (const char* str) { // C++の生の文字列は定数の文字型配列
        cout << str << endl;
    }
    
    return 0;
}