#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    arr[0] = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        arr[i] = x;
        arr[i] = min(arr[i], arr[i - 1]);
    }
    while (q--) {
        int x;
        cin >> x;
        auto it = lower_bound(arr.begin(), arr.end(), x, [](int a, int b) { return a > b; });
        if (it == arr.end()) cout << 0 << '\n';
        else cout << it - arr.begin() << '\n';
    }
    return 0;
}
