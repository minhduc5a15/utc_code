#include <iostream>
#include <cmath>
#include <vector>
#define LIMIT 100001
#define vectori std::vector<int>

std::vector<vectori> max_list(LIMIT, vectori(20));
void init(vectori& arr, int n) {
    for (int i = 0; i < n; ++i) {
        max_list[i][0] = arr[i];
    }
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            max_list[j][i] = std::max(max_list[j][i - 1], max_list[j + (1 << (i - 1))][i - 1]);
        }
    }
    return;
}
int solve(int l, int r) {
    int k = log2(r - l + 1);
    return std::max(max_list[l][k], max_list[r - (1 << k) + 1][k]);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    vectori arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    init(arr, n);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        --l; --r;
        std::cout << solve(l, r) << '\n';
    }
    return 0;
}
