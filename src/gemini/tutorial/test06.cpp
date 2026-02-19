#include <iostream>
using namespace std;

int main()
{
    int scores[5];
    int sum = 0;
    for (int i=0; i<sizeof(scores)/sizeof(scores[0]);i++) {
        cout << "点数" << i+1 << "を入力：";
        cin >> scores[i];
        sum += scores[i];
    }
    int count = sizeof(scores) / sizeof(scores[0]);
    cout << "合計点数：" << sum << ", 平均点：" << double(sum) / count << "です" << endl;

    return 0;
}