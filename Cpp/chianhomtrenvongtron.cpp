#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<ll> arr(m, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr[x - 1]++;
    }

    ll total_sum = 0, total_trip = 0, prefix = 0;
    for (int i = 0; i < m; ++i) {
        total_sum = (total_sum + arr[i]) % MOD;
    }
    for (int j = 0; j < m; ++j) {
        if (j >= 1 && j <= m - 2) {
            ll right = (total_sum - prefix - arr[j]) % MOD;
            if (right < 0) right += MOD;
            ll add = ((arr[j] % MOD) * (prefix % MOD)) % MOD;
            add = (add * right) % MOD;
            total_trip = (total_trip + add) % MOD;
        }
        prefix = (prefix + arr[j]) % MOD;
    }

    int L;
    if (m % 2 == 0) {
        L = m / 2 - 1;
    }
    else {
        L = m / 2;
    }

    vector<ll> v1(2 * m);
    for (int i = 0; i < m; ++i) {
        v1[i] = arr[i];
        v1[i + m] = arr[i];
    }
    vector<ll> v2(2 * m + 1, 0), v3(2 * m + 1, 0);
    for (int i = 0; i < 2 * m; ++i) {
        v2[i + 1] = (v2[i] + v1[i]) % MOD;
        v3[i + 1] = (v3[i] + (v1[i] * v1[i]) % MOD) % MOD;
    }

    ll u = 0;
    for (int i = 0; i < m; ++i) {
        int start = i + 1, end = i + L;
        if (start > end) continue;
        ll w = (v2[end + 1] - v2[start]) % MOD;
        if (w < 0) w += MOD;
        ll s = (v3[end + 1] - v3[start]) % MOD;
        if (s < 0) s += MOD;
        ll pair_sum = ((w * w) % MOD - s) % MOD;
        if (pair_sum < 0) pair_sum += MOD;
        pair_sum = (pair_sum * 500000004) % MOD;
        u = (u + (v1[i] * pair_sum) % MOD) % MOD;
    }
    ll res = (total_trip - u) % MOD;
    if (res < 0) res += MOD;
    cout << res;
    return 0;
}
