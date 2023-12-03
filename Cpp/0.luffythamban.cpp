#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int solve(const std::vector<int>arr) {
    int minDiff = INT_MAX;
    for (int k = *std::min_element(arr.begin(), arr.end()); k <= *std::max_element(arr.begin(), arr.end()); ++k) {
        int diffSum = 0;
        for (const int& num : arr) {
            diffSum += std::abs(num - k);
        }
        minDiff = std::min(minDiff, diffSum);
    }
    return minDiff;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, m;
    std::cin >> n;
    std::vector <int> arr;
    for (int i = 0; i < n; ++i) {
        std::cin >> m;
        arr.push_back(m);
    }
    std::cout << solve(arr) << std::endl;
    return 0;
}

// code by duck it1
