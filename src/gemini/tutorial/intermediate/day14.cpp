#include <iostream>
#include <optional>
using namespace std;

std::optional<float> getDistanceToLeadCar(bool sensor_working) {
    if (sensor_working) {
        return 45.5f;
    } else {
        return std::nullopt;
    }
}

int main()
{
    std::optional<float> opt_dist1 = getDistanceToLeadCar(true);
    std::optional<float> opt_dist2 = getDistanceToLeadCar(false);

    if (opt_dist1) {
        cout << "前走車との距離：" << opt_dist1.value() << endl;
    } else {
        cout << "警告！！" << endl;
    }

    if (opt_dist2) {
        cout << "前走車との距離：" << opt_dist2.value() << endl;
    } else {
        cout << "警告！！" << endl;
    }

    return 0;
}