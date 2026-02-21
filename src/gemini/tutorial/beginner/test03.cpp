#include <iostream>
using namespace std;

int main()
{
    int score;
    cout << "点数を入力：";
    cin >> score;

    if (score < 0 || 100 < score) {
        cout << "無効な点数です";
    } else if (score >= 80) {
        cout << "素晴らしいです！合格です";
    } else if (60 <= score && score < 80) {
        cout << "合格です";
    } else {
        cout << "不合格です";
    }

    return 0;
}