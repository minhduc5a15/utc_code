#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 2000000014;

ll power(ll base, ll exponent, ll modulus = MOD) {
    ll result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll x, maxn = arr.back(), res = 1;
    cin >> x;
    vector<int> dict(maxn + 1, 0);
    for (int i = 2; i <= maxn; ++i) {
        dict[i] += arr.end() - lower_bound(arr.begin(), arr.end(), i);
        if (i <= x) dict[i]--;
        res = (res * power(i, dict[i])) % MOD;
    }
    cout << res;
    return 0;
}
