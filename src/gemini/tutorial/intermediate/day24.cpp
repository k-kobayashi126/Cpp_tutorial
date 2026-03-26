#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

constexpr float SPEED_LIMIT = 100.0f;

void monitorSpeed(float current_speed) {
    auto is_speeding = [limit = SPEED_LIMIT](float s) {return s > limit;};

    this_thread::sleep_for(chrono::milliseconds(500));
    if (is_speeding(current_speed)) {
        cout << "警告：制限速度オーバー" << endl;
    } else {
        cout << "安全" << endl;
    }
}

int main()
{
    float my_speed = 105.0f;
    std::thread t1(monitorSpeed, my_speed);
    t1.join();

    return 0;
}