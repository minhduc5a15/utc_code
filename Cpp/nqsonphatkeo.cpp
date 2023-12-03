#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
bool lambda(std::pair<ll, int>& a, std::pair<ll, int>& b) {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}

void solve(std::vector<ll> arr) {
    std::map<ll, int> counter;
    for (ll item : arr) {
        counter[item]++;
    }
    std::vector<std::pair<ll, int>> items(counter.begin(), counter.end());
    std::sort(items.begin(), items.end(), lambda);
    for (std::pair<ll, int> item : items) {
        std::cout << item.first << ' ';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<ll> arr(n);
    for (int i = 0; i < n; ++i) std::cin >> arr[i];
    solve(arr);
    return 0;
}


// code by duck it1
