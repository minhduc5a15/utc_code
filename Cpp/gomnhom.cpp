#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> valid_number_list(int n) {
    return {n - 1, n, n + 1};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::unordered_map<int, int> count_arr;
    for (const int& item : arr) {
        ++count_arr[item];
    }
    std::vector<int> set_arr(arr.begin(), arr.end());
    std::sort(set_arr.begin(), set_arr.end());
    set_arr.erase(std::unique(set_arr.begin(), set_arr.end()), set_arr.end());
    std::vector<std::vector<int>> arr2;
    for (const int& item : set_arr) {
        std::vector<int> arr1 = valid_number_list(item);
        arr2.push_back({count_arr[arr1[0]], count_arr[arr1[1]], count_arr[arr1[2]]});
    }
    std::vector<int> arr3;
    for (const std::vector<int>& item : arr2) {
        arr3.push_back(std::max(item[1] + item[2], item[1] + item[0]));
    }
    std::cout << *std::max_element(arr3.begin(), arr3.end()) << std::endl;
    return 0;
}
