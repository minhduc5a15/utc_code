#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> arr;
int n, res = INT_MAX;

void solve(int a, int b, int m) {
    if (m == n) {
        res = min(res, abs(a - b));
        return;
    }
    solve(a + arr[m], b, m + 1);
    solve(a, b + arr[m], m + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    solve(0, 0, 0);
    cout << res;
    return 0;
}
