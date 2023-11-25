#include <iostream>
#include <utility>
#include <algorithm>
#define MAX 1000000
int memo[MAX + 1];

void init() {
    memo[1] = 1;
    for (int i = 2; i <= MAX; ++i) {
        long long temp = i;
        int count = 0;
        while (temp != 1 && temp >= i) {
            if (temp % 2 == 0) {
                temp /= 2;
            }
            else {
                temp = 3 * temp + 1;
            }
            ++count;
        }
        memo[i] = count + memo[temp];
    }
}

int solve(int l, int r) {
    if (l > r) std::swap(l, r);
    return *std::max_element(memo + l, memo + r + 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    init();
    int l, r;
    while (std::cin >> l >> r && (l || r)) {
        std::cout << l << " " << r << " " << solve(l, r) << '\n';
    }
    return 0;
}
