#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> speed_history = {40, 55, 62, 48, 70, 50};
    int limit = 60;

    int violations = std::count_if(speed_history.begin(), speed_history.end(), [limit](int speed){return speed > limit;});

    cout << "速度違反件数は " << violations << "です。" << endl;

    return 0;
}