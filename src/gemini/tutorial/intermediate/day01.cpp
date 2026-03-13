#include <iostream>
#include <memory>
using namespace std;

class Camera
{
    private:
        int num;
    public:
        Camera(int num);
        ~Camera();
        void capture() const;
};

Camera::Camera(int num){
    this->num = num;
    cout << "カメラの電源ON" << endl;
}

Camera::~Camera(){
    cout << "カメラの電源OFF" << endl;
}

void Camera::capture() const {
    cout << "画像を撮影しました" << endl;
}

class Car
{
    private:
        unique_ptr<Camera> my_camera;
    public:
        void attachCamera(unique_ptr<Camera> cam);
        void run();
};

void Car::attachCamera(unique_ptr<Camera> cam){
    this->my_camera = move(cam); 
}

void Car::run(){
    my_camera->capture();
}


int main()
{
    unique_ptr<Camera> p1 = make_unique<Camera>(1);
    Car c1 = Car();
    // move()して、ポインタの所有権を移動
    // スマートポインタはコピーできないため、所有権を移動する必要あり
    c1.attachCamera(move(p1));
    c1.run();

    return 0;
} // このスコープを抜けるタイミングでメモリが解放される
