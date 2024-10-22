#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<vector<int>> arr;

int res = INT_MIN;

void solve(int i, int s) {
    if (i == n) {
        res = max(res, s % m);
        return;
    }
    for (int j = 0; j < arr[i].size(); ++j) {
        solve(i + 1, s + arr[i][j]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    arr.assign(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            int y;
            cin >> y;
            arr[i].push_back(y * y);
        }
    }
    solve(0, 0);
    cout << res;
    return 0;
}
