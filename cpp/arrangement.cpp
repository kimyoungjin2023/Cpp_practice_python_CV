#include <iostream>
using namespace std;

int main() {
    int arr[5];   // 크기 5짜리 정수 배열

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
