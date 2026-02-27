#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
    Vector2f local_pos(5.0f, 0.0f);
    Matrix2f rot_matrix;
    rot_matrix << 0.0f, -1.0f,
                  1.0f, 0.0f;
    
    Vector2f global_pos = rot_matrix * local_pos;

    cout << global_pos << endl;

    return 0;
}