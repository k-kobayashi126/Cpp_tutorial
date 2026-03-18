#include <iostream>
using namespace std;

template <typename Derived>
class Controller
{
    public:
        template <typename Func>
        void execute(Func safety_check){
            if (safety_check()) {
                static_cast<Derived*>(this)->executeImpl();
            } else {
                cout << "安全条件を満たしていいないため、制御をキャンセルしました" << endl;
            }
        }
};

class Accelerator : public Controller<Accelerator>
{
    public:
        void executeImpl() {
            cout << "アクセルを踏み込みます" << endl;
        }
};

class Brake : public Controller<Brake>
{
    public:
        void executeImpl() {
            cout << "ブレーキをかけます" << endl;
        }
};

int main()
{
    Accelerator acc;
    Brake brake;

    float distance = 10.0f;

    acc.execute([distance](){return distance > 20;});
    brake.execute([distance](){return distance <= 20;});

    return 0;
}