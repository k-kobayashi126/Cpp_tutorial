#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
    Translation2f translation(10.0f, 20.0f); // 自動運転車のグローバル座標
    Rotation2Df rotation(M_PI / 2.0f); // 自動運転車のグローバル向き

    Affine2f transform = translation * rotation;

    Vector2f local_pos(5.0f, 0.0f); // 自動運転車が捉えた障害物のローカル座標

    Vector2f global_pos = transform * local_pos;

    cout << "変換後の座標：" << global_pos << endl;

    return 0;
}