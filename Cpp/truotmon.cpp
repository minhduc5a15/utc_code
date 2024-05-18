#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vi;

vi solve(vi &arr, const vi &queries) {
    std::sort(arr.begin(), arr.end());
    vi result;
    for (int query: queries) {
        int count = std::upper_bound(arr.begin(), arr.end(), query) - arr.begin();
        result.push_back(count);
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    vi arr(n), queries(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> queries[i];
    }
    vi result = solve(arr, queries);
    for (int res: result) { std::cout << res << '\n'; }
    return 0;
}

