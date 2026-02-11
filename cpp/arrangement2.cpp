#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    v.push_back(40);
    v.push_back(50);

    for (int x : v) {
        cout << x << " ";
    }
}