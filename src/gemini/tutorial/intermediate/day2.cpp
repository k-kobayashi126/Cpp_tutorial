#include <iostream>
#include <memory>
using namespace std;

class LidarData
{
    public:
        LidarData();
        ~LidarData();
};

LidarData::LidarData(){
    cout << "LiDARデータ取得" << endl;
}

LidarData::~LidarData(){
    cout << "LiDARデータ破棄" << endl;
}


class AutoDriveModule
{
    private:
        shared_ptr<LidarData> my_data;
    public:
        void setLidarData(shared_ptr<LidarData> data);
};

void AutoDriveModule::setLidarData(shared_ptr<LidarData> data){
    this->my_data = data;
}


int main()
{
    // 何人がそのポインタを共有しているかを確認できるポインタ
    shared_ptr<LidarData> lidar_ptr = make_shared<LidarData>();
    cout << "現在の共有者数：" << lidar_ptr.use_count() << endl; // 1

    {
        AutoDriveModule perception;
        AutoDriveModule planning;

        perception.setLidarData(lidar_ptr);
        cout << "現在の共有者数：" << lidar_ptr.use_count() << endl; // 2
        planning.setLidarData(lidar_ptr);
        cout << "現在の共有者数：" << lidar_ptr.use_count() << endl; // 3
    } // スコープを抜けるときに、スコープ内で定義したポインタは破棄
    cout << "現在の共有者数：" << lidar_ptr.use_count() << endl; // 1

    return 0;
} // lidar_ptrも破棄