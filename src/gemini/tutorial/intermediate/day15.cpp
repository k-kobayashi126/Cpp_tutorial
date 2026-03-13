#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void readCamera() {
    cout << "カメラ画像を取得中..." << endl;
    this_thread::sleep_for(chrono::seconds(4));
    cout << "カメラ画像処理　終了" << endl;
}

void readLidar() {
    cout << "LiDAR点群を取得中..." << endl;
    this_thread::sleep_for(chrono::seconds(6));
    cout << "LiDARの処理　終了" << endl;
}

int main()
{
    cout << "メインシステム起動" << endl;

    std::thread t1(readCamera);

    std::thread t2(readLidar);

    t1.join();
    t2.join();

    cout << "全センサー終了" << endl;


    return 0;
}