#include <iostream>
#include <vector>
using namespace std;


int solve(const vector<int> &arr, int n) {
    vector<int> pos(n + 1);
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
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vector<int> arr;
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

