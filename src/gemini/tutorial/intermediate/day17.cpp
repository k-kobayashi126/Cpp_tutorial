#include <iostream>
#include <memory>
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

using PointCloud = etl::vector<Point3D, 100>;

unique_ptr<PointCloud> generateLidarData() {
    unique_ptr<PointCloud> data = make_unique<PointCloud>();
    data->push_back(Point3D(1.0f, 2.0f, 3.0f));
    data->push_back(Point3D(10.0f, 20.0f, 30.0f));
    data->push_back(Point3D(100.0f, 200.0f, 300.0f));

    return data;
}

class PerceptionModule
{
    public:
        void processData(unique_ptr<PointCloud> data) {
            cout << "受信した点群の数：" << data->size() << endl;
        }
};

int main()
{
    unique_ptr<PointCloud> sensor_data = generateLidarData();
    PerceptionModule per = PerceptionModule();
    per.processData(std::move(sensor_data));

    if (sensor_data == nullptr) {
        cout << "もとのデータは空になりました" << endl;
    }

    return 0;
}