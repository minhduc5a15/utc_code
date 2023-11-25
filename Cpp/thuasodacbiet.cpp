#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define vector std::vector<ll>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    vector arr = { 1, 2, 5, 10, 20, 25, 50 };
    vector root = { 100, 125, 200, 250, 500 };
    arr.reserve(8 * root.size() + arr.size() + 1);
    for (int i = 1; i < 8; i++) {
        arr.insert(arr.end(), root.begin(), root.end());
        for (ll& item : root) {
            item *= 10;
        }
    }
    arr.push_back(1000000000);

    int n;
    std::cin >> n;
    vector list;
    list.reserve(n);
    for (int i = 0; i < n; ++i) {
        ll num;
        std::cin >> num;
        list.push_back(num);
    }
    int index = 0;
    for (ll &item : list) {
        index++;
        int count = std::upper_bound(arr.begin(), arr.end(), item) - arr.begin();
        std::cout << "#Case " << index << ": " << count << "\n";
    }

    return 0;
}
