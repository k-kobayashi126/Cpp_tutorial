#include <iostream>
#include <memory>
using namespace std;

class VehicleState
{
    public:
        float speed;
        VehicleState(float speed);
};

VehicleState::VehicleState(float speed){
    this->speed = speed;
}

template <typename Derived>
class ControlStrategy
{
    protected:
        std::shared_ptr<VehicleState> state_ptr;
    public:
        void setState(std::shared_ptr<VehicleState> s) {
            this->state_ptr = s;
        }
        void execute() {
            static_cast<Derived*>(this)->executeImpl();
        }
};

class HighwayControl : public ControlStrategy<HighwayControl>
{
    public:
        void executeImpl() {
            if (state_ptr) {
                cout << "高速道路モード：時速" << state_ptr->speed << "で巡航します。" << endl;
            } else {
                cout << "状態を取得できません" << endl;
            }
        }
};

int main()
{
    shared_ptr<VehicleState> shared_state = make_shared<VehicleState>(80.0f);
    HighwayControl highway_mode;
    highway_mode.setState(shared_state);
    highway_mode.execute();

    return 0;
}