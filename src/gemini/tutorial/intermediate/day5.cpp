#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
    Vector3f current_pos(10.0f, 5.0f, 0.0f);
    Vector3f velocity(2.0f, 0.0f, 0.0f);
    float time = 2.0f;

    Vector3f next_pos = current_pos + velocity * time;

    cout << "次の位置 x：" << next_pos.x() << endl;
    cout << "次の位置 y：" << next_pos.y() << endl;
    cout << "次の位置 z：" << next_pos.z() << endl;

    return 0;
}