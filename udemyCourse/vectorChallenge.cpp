#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2;

    v1.push_back(10);
    v1.push_back(20);
    v2.push_back(100);
    v2.push_back(200);

    cout << "v1: " << v1.at(0) << "\n";
    cout << "v2: " << v2.at(0) << "\n";

    cout << "v1 contains " << v1.size() << " elements" << '\n';
    cout << "v2 contains " << v2.size() << " elements" << '\n';
    
    // add both vectors to a 2d vector
    vector<vector<int>> v2d;

    v2d.push_back(v1);
    v2d.push_back(v2);

    cout << "v2d: " << v2d.at(0).at(0) << " " << v2d.at(0).at(1) << "\n";
    cout << "v2d: " << v2d.at(1).at(0) << " " << v2d.at(1).at(1) << "\n";

    v1.at(0) = 1000;

    cout << "v1: " << v1.at(1);


    return 0;
}