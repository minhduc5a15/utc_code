#include<iostream>

int main() {
    int n, count = 0;
    std::cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    for (int i = 1; i < n - 1 ; ++i) {
        if ((arr[i] > arr[i - 1]) && arr[i] > arr[i + 1]) {
            count++;
        }
    }
    std::cout << count;
    return 0;
}
