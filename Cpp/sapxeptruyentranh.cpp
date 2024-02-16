#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int solve(const vi &arr, int n) {
    vi pos(n + 1);
    for (int i = 0; i < n; ++i) {
        pos[arr[i]] = i;
    }
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        if (pos[i] <= pos[i - 1]) {
            ++res;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vi arr;
    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        arr.resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        cout << "#Case " << i << ": " << solve(arr, n) << '\n';
        arr.clear();
    }
    return 0;
}

