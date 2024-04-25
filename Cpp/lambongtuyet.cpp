#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

void solve(const vll &V, const vll &T, const vll &prefix_sum, int n) {
    priority_queue<ll, vll, greater<>> q;
    ll res;
    for (int i = 1; i <= n; ++i) {
        res = 0;
        q.push(V[i] + prefix_sum[i - 1]);
        while (!q.empty() && q.top() <= prefix_sum[i]) {
            res += q.top() - prefix_sum[i - 1];
            q.pop();
        }
        res += T[i] * q.size();
        cout << res << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vll V(n + 1), T(n + 1), prefix_sum(n + 1, 0);
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
