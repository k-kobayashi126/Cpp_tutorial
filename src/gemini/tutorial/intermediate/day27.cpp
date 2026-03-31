#include <iostream>
#include <thread>
#include <mutex>
#include <optional>
#include <memory>
#include <eigen3/Eigen/Dense>
#include <etl/vector.h>
using namespace std;
using namespace Eigen;

constexpr float DANGER_DISTANCE = 5.0f;
etl::vector<Vector2f, 5> obstacle_buffer;
std::mutex mtx;

class VehicleState
{
    public:
        float speed;
        VehicleState(float s);
};

VehicleState::VehicleState(float s) {
    this->speed = s;
}


template <typename Derived>
class Controller
{
    protected:
        std::shared_ptr<VehicleState> state_ptr;
    public:
        void setState(std::shared_ptr<VehicleState> s) {
            this->state_ptr = s;
        }
        
        template <typename Func> 
        void execute(Func is_danger) {
            if (is_danger()) {
                static_cast<Derived*>(this)->emergencyImpl();
            } else {
                static_cast<Derived*>(this)->normalImpl();
            }
        }
};


class EmergencySystem : public Controller<EmergencySystem>
{
    public:
        void emergencyImpl(){cout << "緊急ブレーキ" << endl;}
        void normalImpl(){cout << "正常" << endl;}
};

void sensorLoop() {
    Vector2f obs1(3.0f, 4.0f);
    Vector2f obs2(1.0f, 1.0f);
    Vector2f obs3(6.0f, 8.0f);

    std::lock_guard<std::mutex> lock(mtx);
    if (!obstacle_buffer.full()) {
        obstacle_buffer.push_back(obs1);
        obstacle_buffer.push_back(obs2);
        obstacle_buffer.push_back(obs3);
    }
}

std::optional<Vector2f> getClosestObstacle() {
    std::lock_guard<std::mutex> lock(mtx);
    if (obstacle_buffer.empty()) {
        return std::nullopt;
    } else {
        int min_idx = -1;
        float min_dis = 10000;
        for (int i=0; i<obstacle_buffer.size(); i++) {
            float tmp_dis = obstacle_buffer[i].norm();
            if (tmp_dis < min_dis) {
                min_dis = tmp_dis;
                min_idx = i;
            }
        }
        return obstacle_buffer[min_idx];
    }
}


int main()
{
    std::shared_ptr<VehicleState> ptr = std::make_shared<VehicleState>(60.0f);
    EmergencySystem sys;
    sys.setState(ptr);

    std::thread t1(sensorLoop);
    t1.join();
    std::optional<Vector2f> opt_obs = getClosestObstacle();

    if (opt_obs) {
        float distance = opt_obs.value().norm();
        sys.execute([distance](){return DANGER_DISTANCE > distance;});
    } else {
        cout << "エラー" << endl;
    }
}