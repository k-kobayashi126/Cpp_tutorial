#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outfile("./test16.txt");
    outfile << "初のファイル処理1" << endl;
    outfile << "初のファイル処理2" << endl;
    outfile.close();

    return 0;
}