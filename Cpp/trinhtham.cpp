#include <iostream>
#include <deque>
#include <vector>
void solve(std::vector<int>& arr, int n, int k) {
    std::deque<int> Qi(k);
    int i;
    for (i = 0; i < k; ++i) {
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    for (; i < n; ++i) {
        std::cout << arr[Qi.front()] << " ";
        while ((!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    std::cout << arr[Qi.front()] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    solve(arr, n, k);
    return 0;
}
