#include <array>
#include <iostream>
using namespace std;

int main() {
    array<int, 5> arr = {1, 2, 3, 4, 5};

    for (int x : arr) {
        cout << x << " ";
    }
}
