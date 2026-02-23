#include <iostream>
#include <memory>
using namespace std;

class ECU;

class Car
{
    public:
        shared_ptr<ECU> my_ecu;
        Car();
        ~Car();
        void honk();
};

Car::Car(){
    cout << "車を生成" << endl;
}

Car::~Car(){
    cout << "車を破棄" << endl;
}

void Car::honk(){
    cout << "プップー" << endl;
}


class ECU
{
    public:
        weak_ptr<Car> my_car;
        ECU();
        ~ECU();
        void checkCarStatus();
};

ECU::ECU(){
    cout << "ECUを生成" << endl;
}

ECU::~ECU(){
    cout << "ECUを破棄" << endl;
}

void ECU::checkCarStatus(){
    shared_ptr<Car> temp_car = my_car.lock();
    if (temp_car) {
        temp_car->honk();
    } else {
        cout << "車はすでに破棄されています" << endl;
    }
}

int main()
{
    shared_ptr<ECU> ecu = make_shared<ECU>();

    {
        shared_ptr<Car> car = make_shared<Car>();
        cout << car.use_count() << ecu.use_count() <<endl;
        car->my_ecu = ecu;
        ecu->my_car = car;

        cout << car.use_count() << ecu.use_count() <<endl;

        ecu->checkCarStatus();
        cout << car.use_count() << ecu.use_count() <<endl;
    }
    cout << ecu.use_count() <<endl;
    ecu->checkCarStatus();
    cout <<  ecu.use_count() <<endl;

    return 0;
} 