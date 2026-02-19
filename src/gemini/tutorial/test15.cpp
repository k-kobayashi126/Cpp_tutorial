#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    int num = 1;

    while (num!=0) {
        cout << "整数を入力：";
        cin >> num;
        cout << endl;

        if (num!=0){
            numbers.push_back(num);
        }
    }

    cout << "numbersの要素：";
    for (int i=numbers.size()-1; i>=0; i--) {
        cout << numbers[i] << ", ";
    }

    return 0;
}