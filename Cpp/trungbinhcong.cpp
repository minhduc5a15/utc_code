#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, average = 0, count = 0;
    std::cin >> n;
    if (n == 0) {
        std::cout << "0 0";
    }
    else {
        int arr[n];
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
            average += arr[i];
        }
        average /= n;
        for (int i = 0; i < n; ++i) {
            if (arr[i] < average) count++;
        }
        std::cout << average << " " << count;
    }
    return 0;
}

