#include <iostream>
#include <memory>
#include <optional>
using namespace std;

class MapData
{
    public:
        MapData(){
            cout << "地図ロード" << endl;
        }
        ~MapData(){
            cout << "地図破棄" << endl;
        }
};

class PlanningModule
{
    private:
        std::weak_ptr<MapData> map_ptr;
    public:
        void setMap(std::shared_ptr<MapData> map);
        std::optional<float> calculateRoute();
};

void PlanningModule::setMap(std::shared_ptr<MapData> map) {
    map_ptr = map;
}

std::optional<float> PlanningModule::calculateRoute() {
     // weak_ptrを参照するには.lockが必要。データかnullptr
    std::shared_ptr<MapData> tmp = map_ptr.lock();
    if (tmp) {
        return 15.5f;
    } else {
        return std::nullopt;
    }
}

int main()
{
    PlanningModule planner;
    {
        std::shared_ptr<MapData> map_server = make_shared<MapData>();
        planner.setMap(map_server);

        std::optional<float> result1 = planner.calculateRoute();
        if (result1) {
            cout << result1.value() << endl;
        } else {
            cout << "エラー" << endl;
        }
    }
    std::optional<float> result2 = planner.calculateRoute();
    if (result2) {
        cout << result2.value() << endl;
    } else {
        cout << "エラー" << endl;
    }

    return 0;
}