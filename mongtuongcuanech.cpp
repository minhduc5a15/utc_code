#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vi next(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            next[i] = s.top();
        }
        s.push(i);
    }
    int max_log = __lg(n) + 1;
    vector<vi> pre(n, vi(max_log, -1));
    for (int i = 0; i < n; ++i) {
        pre[i][0] = next[i];
    }
    for (int j = 1; j < max_log; ++j) {
        for (int i = 0; i < n; ++i) {
            if (pre[i][j - 1] != -1) {
                pre[i][j] = pre[pre[i][j - 1]][j - 1];
            }
        }
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        x--;
        for (int j = max_log - 1; j >= 0; --j) {
            if (k >= (1 << j) && pre[x][j] != -1) {
                x = pre[x][j];
                k -= (1 << j);
            }
        }
        cout << arr[x] << '\n';
    }
    return 0;
}