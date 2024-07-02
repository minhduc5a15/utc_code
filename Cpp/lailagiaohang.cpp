#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<ll> q;
    vector<pll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    int j = n - 1;
    ll res = 0;
    while (--n) {
        while (j >= 0 and arr[j].first >= n) {
            q.push(arr[j--].second);
        }
        if (!q.empty()) {
            res += q.top();
            q.pop();
        }
    }
    cout << res;
    return 0;
}
