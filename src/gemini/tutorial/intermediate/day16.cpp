#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int danger_score = 0;
std::mutex mtx;

void analyzeCamera() {
    for (int i=0; i<100000; i++) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            danger_score++;
        }
    }
}

int main()
{
    std::thread t1(analyzeCamera);
    std::thread t2(analyzeCamera);

    t1.join();
    t2.join();

    cout << "最終カウント：" << danger_score << endl;

    return 0;
}