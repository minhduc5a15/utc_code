#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n, q;
    cin >> m >> n >> q;
    vector<pair<ll, ll>> v_a(m + 1, {INT_MIN, INT_MAX}), v_b(n + 1, {INT_MIN, INT_MAX});
    for (int i = 1; i <= m; ++i) {
        cin >> v_a[i].first;
        v_a[i] = {max(v_a[i - 1].first, v_a[i].first), min(v_a[i - 1].second, v_a[i].first)};
    }
    for (int i = 1; i <= n; ++i) {
        cin >> v_b[i].first;
        v_b[i] = {max(v_b[i - 1].first, v_b[i].first), min(v_b[i - 1].second, v_b[i].first)};
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        ll a = v_a[u].first * v_b[v].first;
        ll b = v_a[u].first * v_b[v].second;
        ll c = v_a[u].second * v_b[v].second;
        ll d = v_a[u].second * v_b[v].first;
        cout << max(max(a, b), max(c, d)) << ' ' << min(min(a, b), min(c, d)) << '\n';
    }
    return 0;
}
