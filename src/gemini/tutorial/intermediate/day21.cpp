#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include<etl/vector.h>
using namespace std;

etl::vector<int, 5> shared_buffer;
std::mutex mtx;

void runLidar() {
    for (int i=0; i<5; i++) {
        this_thread::sleep_for(chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(mtx);

        if (!shared_buffer.full()) {
            shared_buffer.push_back(i);
            cout << "LiDAR: データ[" << i << "]を生成しました" << endl;
        }
    }
}

void runPerception() {
    for (int i=0; i<5; i++) {
        this_thread::sleep_for(chrono::milliseconds(150));
        std::lock_guard<std::mutex> lock(mtx);

        if (!shared_buffer.empty()) {
            int data = shared_buffer.back();
            shared_buffer.pop_back();
            cout << "Perceptionデータ[" << data << "]を処理しました" << endl;
        }
    }
}

int main()
{
    std::thread t1(runLidar);;
    std::thread t2(runPerception);

    t1.join();
    t2.join();

    cout << "全システム終了" << endl;

    return 0;
}