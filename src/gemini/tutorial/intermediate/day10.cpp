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
    etl::vector<Point3D, 5> safe_buffer;

    for (int i=0; i<6; i++) {
        if (safe_buffer.full()) {
            cout << "警告！バッファが満杯です。データを破棄します" << endl;
            break;
        } else {
            safe_buffer.push_back(Point3D(1, 2, 3));
        }
    }

    cout << "バッファのサイズ：" << safe_buffer.size() << endl;

    return 0;
}