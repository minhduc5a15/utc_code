#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

void solve(const vector<ll>& V, const vector<ll>& T, const vector<ll> &prefix_sum, int n) {
    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll res;
    for (int i = 1; i <= n; ++i) {
        res = 0;
        q.push(V[i] + prefix_sum[i - 1]);
        while (!q.empty() && q.top() <= prefix_sum[i]) {
            res += q.top() - prefix_sum[i - 1];
            q.pop();
        }
        res += T[i] * q.size();
        cout << res << " ";
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> V(n + 1), T(n + 1), prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> V[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> T[i];
        prefix_sum[i] = prefix_sum[i - 1] + T[i];
    }
    solve(V, T, prefix_sum, n);
    return 0;
}
