#include <iostream>
#include <thread>
#include <mutex>
#include <eigen3/Eigen/Dense>
using namespace std;
using namespace Eigen;

Vector2f closest_obstacle(100.0f,100.0f);
std::mutex mtx;

void processRadar() {
    Vector2f radar_obs(5.0f, 2.0f);
    std::lock_guard<std::mutex> lock(mtx);

    if (radar_obs.norm() < closest_obstacle.norm()) {
        closest_obstacle = radar_obs;
        cout << "障害物を更新しました" << endl;
    }
}

void processCamera() {
    Vector2f cam_obs(12.0f, 0.0f);
    std::lock_guard<std::mutex> lock(mtx);

    if (cam_obs.norm() < closest_obstacle.norm()) {
        closest_obstacle = cam_obs;
        cout << "障害物を更新しました" << endl;
    }
}

int main()
{
    std::thread t1(processRadar);
    std::thread t2(processCamera);

    t1.join();
    t2.join();

    if (closest_obstacle.norm() < 10.0f) {
        cout << "緊急ブレーキ" << endl;
    } else {
        cout << "安全な距離" << endl;
    }

    return 0;
}