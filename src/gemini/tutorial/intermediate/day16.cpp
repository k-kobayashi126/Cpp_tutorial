#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int shared_counter = 0;
std::mutex mtx;

void countUp() {
    for (int i=0; i<100000; i++) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            shared_counter++;
        }
    }
}

int main()
{
    std::thread t1(countUp);
    std::thread t2(countUp);

    t1.join();
    t2.join();

    cout << "最終カウント：" << shared_counter << endl;

    return 0;
}