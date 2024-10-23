#include <iostream>
#include <vector>
#include <algorithm>

long long solve(std::vector<int>& arr, int n, int k) {
    std::ranges::sort(arr);
    int left = 0, right = n - 1;
    long long count = 0;
    while (left < right) {
        if (arr[left] + arr[right] <= k) {
            count += right - left;
            left++;
        }
        else {
            right--;
        }
    }
    return count;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << solve(arr, n, k);
    return 0;
}

