#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "一つ目の整数を入力してください：";
    cin >> num1;

    cout << "二つ目の整数を入力してください：";
    cin >> num2;

    int sum = num1 + num2;
    int mul = num1 * num2;
    double mean = (double(num1) + double(num2)) / 2.0;

    cout << "(和 / 積 / 平均)：(" << sum << " / " << mul << " / " << mean << ")" << endl;

    return 0;
}