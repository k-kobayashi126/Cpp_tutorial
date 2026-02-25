#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> point_cloud;

    for (int i=0; i<1000; i++) {
        point_cloud.push_back(i);
    }
    cout << point_cloud.size() << endl;

    vector<int> processed_cloud;
    processed_cloud = move(point_cloud);

    cout << point_cloud.size() << processed_cloud.size() << endl;

    return 0;
}