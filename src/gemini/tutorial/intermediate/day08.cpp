#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    Vector3f obstacle(10.0f, 0.0f, 0.0f);

    Quaternionf q(AngleAxisf(M_PI / 2.0f, Vector3f::UnitY()));

    Vector3f rotated_obstacle = q * obstacle;

    cout << rotated_obstacle << endl;

    return 0;
}