#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    sort(arr.begin(), arr.end(), [](const pll &a, const pll &b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    });
    int j = n - 1;
    ll res = 0;
    while (n) {
        while (j >= 0 && arr[j].first >= n) {
            q.push(arr[j].second);
            --j;
        }
        if (!q.empty()) {
            res += q.top();
            q.pop();
        }
        --n;
    }
    cout << res;
    return 0;
}
