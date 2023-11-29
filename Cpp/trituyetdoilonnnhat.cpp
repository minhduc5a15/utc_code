#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    std::vector<long long> arr_1, arr_2;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        if (arr[i] < 0) {
            arr_1.push_back(arr[i]);
        }
        else if (arr[i] > 0) {
            arr_2.push_back(arr[i]);
        }
    }
    std::sort(arr_1.begin(), arr_1.end());
    std::sort(arr_2.begin(), arr_2.end(), std::greater<long long>());
    long long result = std::max((arr_1[0] + arr_1[1]) * -1, arr_2[0] + arr_2[1]);
    std::cout << result << std::endl;
    return 0;
}
