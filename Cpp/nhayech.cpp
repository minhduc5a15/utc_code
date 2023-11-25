#include <iostream>
#include <vector>

bool solve(std::vector<int>& arr, int n) {
    int max_reach = arr[0];
    for (int i = 0; i < n; i++) {
        if (i > max_reach) return false;
        max_reach = std::max(max_reach, i + arr[i]);
    }
    return true;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        if (solve(arr, n)) std::cout << "True\n";
        else std::cout << "False\n";
    }
    return 0;
}