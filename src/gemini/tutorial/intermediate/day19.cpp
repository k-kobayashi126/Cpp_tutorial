#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace std;
using namespace Eigen;

constexpr float deg2rad(float deg) {
    float rad = deg * (3.14159265f / 180.0f);

    return rad;
}

int main()
{
    constexpr float rad = deg2rad(45.0f);

    // 平行移動
    Translation2f translation(100.0f, 50.0f);
    // 回転移動
    Rotation2Df rotation(rad);

    // アフィン変換
    Affine2f transform = translation * rotation;

    // 車原点の障害物の座標
    Vector2f local_pos(10.0f, 0.0f);

    // 地図上のグローバル座標へ変換
    Vector2f global_obs = transform * local_pos;

    cout << "グローバル座標は " << global_obs << endl;

    return 0;
}