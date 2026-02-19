#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "../include/Car.h"
#include "../include/Obstacle.h"
using namespace std;

int main()
{
    Car car(10, 10);
    Obstacle obstacle(10, 0);

    srand(time(0));
    int score = 0;
    cout << "通算逃げ切り回数：" << score << endl;
    while (true) {
        // 【魔法のコード】ターミナル画面を一度まっさらにクリアする（ANSIエスケープシーケンス）
        cout << "\x1B[2J\x1B[H";

        // === 画面描画フェーズ ===
        // Y=0 (画面の一番上) から Y=10 (車のある位置) まで、1行ずつ上から描画する
        for (int y = 0; y <= car.getY(); y++) {
            
            if (y == obstacle.getY()) {
                // 今描いている行が、障害物のY座標と同じなら爆弾を描画
                cout << string(obstacle.getX(), ' ') << "💣" << endl;
            } 
            else if (y == car.getY()) {
                // 今描いている行が、車のY座標と同じなら車を描画
                cout << string(car.getX(), ' ') << "🚗" << endl;
            } 
            else {
                // どちらでもない行は、ただの「空間」なので改行だけして隙間を作る
                cout << endl; 
            }
        }

        cout << "コマンドを入力 (a:左, d:右, q:終了) → ";
        char command;
        cin >> command;

        if (command == 'a') {
            car.moveLeft();
            obstacle.moveDown(); // 入力されるたびに爆弾がY軸を下る
        } else if (command == 'd') {
            car.moveRight();
            obstacle.moveDown(); // 入力されるたびに爆弾がY軸を下る
        } else if (command == 'q') {
            cout << score << "回逃げ切りに成功！！" << endl;
            break;
        }

        if (car.getY()==obstacle.getY()) {
            if (car.getX()==obstacle.getX())  {
                cout << "ゲームオーバー！！" << "通算逃げ切り回数：" << score << endl;
                break;
            } else {
                score++;
                cout << "逃げ切り成功！！" << "通算逃げ切り回数：" << score << endl;
                this_thread::sleep_for(std::chrono::seconds(2));

                int randomX = rand() % 20;
                obstacle.resetPosition(randomX, 0);
            }
        }
    }
    
    return 0;
}