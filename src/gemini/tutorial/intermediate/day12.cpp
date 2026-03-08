#include <iostream>
using namespace std;

// constexprを付けた関数（手元のPCでコンパイルする時に計算が完了する！）
constexpr float kmh_to_ms(float kmh) {
    return kmh * (1000.0f / 3600.0f);
}

int main() {
    // コンパイルした時点で、この行は内部的に float rad = 1.570796f; と全く同じになる（計算コストゼロ！）
    constexpr float speed_ms = kmh_to_ms(108.0f); 

    cout << "108[km/h] は " << speed_ms << "[m/s] です。" << endl;
    return 0;
}