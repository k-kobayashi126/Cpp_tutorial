#include <iostream>
#include <etl/vector.h>
using namespace std;

class Point3D
{
    private:
        float x;
        float y;
        float z;
    public:
        Point3D(float x, float y, float z);
};

Point3D::Point3D(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

int main()
{
    etl::vector<Point3D, 5> lidar_buffer;
    lidar_buffer.push_back(Point3D(1.0f, 2.0f, 3.0f));
    lidar_buffer.push_back(Point3D(1.0f, 2.0f, 3.0f));
    lidar_buffer.push_back(Point3D(1.0f, 2.0f, 3.0f));

    cout << lidar_buffer.size() << ", " << lidar_buffer.capacity() << endl;

    return 0;
}
