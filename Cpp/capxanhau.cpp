#include <iostream>
#include <vector>
#include <deque>

typedef std::vector<int> vector;
typedef std::deque<int> deque;
typedef std::vector<std::deque<int>> vector_d;

vector solve(vector& arr, int n, int k) {
    vector_d indices(1001);
    for (int i = 0; i < k; ++i) {
        indices[arr[i]].emplace_back(i);
    }
    vector result;
    result.reserve(n - k + 1);
    for (int i = k; i <= n; ++i) {
        int max_dist = 0;
        for (deque& deq : indices) {
            while (!deq.empty() && deq.front() < i - k) {
                deq.pop_front();
            }
            if (deq.size() >= 2) {
                max_dist = std::max(max_dist, deq.back() - deq.front());
            }
        }
        result.emplace_back(max_dist);
        if (i < n) {
            indices[arr[i]].emplace_back(i);
        }
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, k;
    std::cin >> n >> k;
    vector arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    vector result = solve(arr, n, k);
    for (int res : result) std::cout << res << " ";
    return 0;
}
