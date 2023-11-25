#include <iostream>
#include <vector>
#include <algorithm>
long long solve(std::vector<int>& list, int n, int k) {
    std::sort(list.begin(), list.end());
    int left = 0, right = n - 1;
    long long count = 0;
    while (left < right) {
        if (list[left] + list[right] <= k) {
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
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << solve(arr, n, k);
    return 0;
}
