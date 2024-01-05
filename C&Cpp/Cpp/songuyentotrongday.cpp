#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    std::cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    for (int item: arr) {
        if (isPrime(item)) std::cout << item << " ";
    }
    return 0;
}
