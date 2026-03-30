#include <iostream>
#include <thread>
#include <mutex>
#include <optional>
#include <chrono>
#include <eigen3/Eigen/Dense>
#include <etl/vector.h>
using namespace std;
using namespace Eigen;


constexpr float DANGER_RADIUS = 7.0f;
etl::vector<Vector2f, 3> obstacle_buffer;
std::mutex mtx;

void scanEnvironment() {
    Vector2f obs1(6.0f, 8.0f);
    Vector2f obs2(3.0f, 4.0f);
    Vector2f obs3(10.0f, 0.0f);

    std::lock_guard<std::mutex> lock(mtx);
    if (!obstacle_buffer.full()) {
        obstacle_buffer.push_back(obs1);
        obstacle_buffer.push_back(obs2);
        obstacle_buffer.push_back(obs3);
    }
}

std::optional<Vector2f> getMostDangerousObstacle() {
    std::lock_guard<std::mutex> lock(mtx);
    if (obstacle_buffer.empty()) {
        return std::nullopt;
    } else {
        float min_value = 100000;
        int min_idx = -1;
        for (int i=0; i<obstacle_buffer.size(); i++) {
            float tmp_dis = obstacle_buffer[i].norm();
            if (tmp_dis < min_value) {
                min_value = tmp_dis;
                min_idx = i;
            }
        }
        return obstacle_buffer[min_idx];
    }
}

int main()
{
    std::thread t1(scanEnvironment);
    t1.join();

    std::optional<Vector2f> opt_obs = getMostDangerousObstacle();
    if (opt_obs) {
        float distance = opt_obs.value().norm();
        if (distance < DANGER_RADIUS) {
            cout << "衝突回避システム作動" << endl;
        } else {
            cout << "安全な距離" << endl;
        }
    } else {
        cout << "障害物を取得できませんでした" << endl;
    }

    return 0;
}