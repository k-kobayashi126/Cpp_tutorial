#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "正の整数を入力：";
    cin >> n;

    int sum = 0;
    for (int i=1;i<=n;i++) {
        sum += i;
    }
    cout << "合計値：" << sum << endl;

    return 0;
}