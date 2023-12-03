#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
typedef std::vector<int> vector;
ll solve(vector& arr, int t) {
    ll left = 1, right = *max_element(arr.begin(), arr.end()) * (ll) t;
    while (left < right) {
        ll mid = (left + right) / 2;
        ll total = 0;
        for (int& item: arr) {
            total += mid / item;
        }
        if (total >= t) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, t;
    std::cin >> n >> t;
    vector arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << solve(arr, t);
    return 0;
}


// code by duck it1
