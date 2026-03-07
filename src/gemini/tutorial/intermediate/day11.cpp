#include <iostream>
using namespace std;

template <typename Derived>
class Controller
{
    public:
        void execute() {
            static_cast<Derived*>(this)->executeImpl();
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
    Accelerator accelerator;
    Brake brake;

    accelerator.execute();
    brake.execute();

    return 0;
}