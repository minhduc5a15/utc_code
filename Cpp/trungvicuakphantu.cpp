#include <iostream>
#include <vector>
#include <set>
#define duck int main
using namespace std;

void solve(vector<int>& arr, int n, int k) {
    multiset<int> window(arr.begin(), arr.begin() + k);
    auto mid = next(window.begin(), k / 2);
    for (int i = k; i <= n; ++i) {
        cout << *prev(mid, 1 - (k % 2)) << ' ';
        window.insert(arr[i]);
        if (arr[i] < *mid) {
            --mid;
        }
        if (arr[i - k] <= *mid) {
            ++mid;
        }
        window.erase(window.lower_bound(arr[i - k]));
    }
    return;
}

duck() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    solve(arr, n, k);
    return 0;
}
