#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;
const int MOD = 1000000007;

unordered_map<int, ll> mp;

ll solve(int n) {
    if (mp.find(n) != mp.end()) return mp[n];
    if (n == 0) return mp[n] = 1;
    ll count = 0;
    for (int a = 1; a * a <= n; ++a) {
        if (n % a) continue;
        count = (count + solve((a - 1) * (n / a + 1))) % MOD;
    }
    return mp[n] = count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << solve(x) << '\n';
    }
    return 0;
}
