#include <iostream>
#include <cmath>
#include <optional>
#include <eigen3/Eigen/Dense>
using namespace std;
using namespace Eigen;

std::optional<Vector3f> getLidarPoint(bool is_valid) {
    if (is_valid) {
        return Vector3f(12.0f, 0.0f, 0.0f);
    } else {
        return std::nullopt;
    }
}

int main()
{
    std::optional<Vector3f> opt_point = getLidarPoint(true);

    if (opt_point) {
        Quaternionf q(AngleAxisf(M_PI / 2.0f, Vector3f::UnitY()));
        Vector3f rotated_point = q * opt_point.value();
        cout << "回転後の座標：" << rotated_point << endl;
    } else {
        cout << "警告：センサーデータを取得できませんでした" << endl;
    }

    return 0;
}