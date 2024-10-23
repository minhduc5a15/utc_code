#include <iostream>
using namespace std;
typedef long long ll;

ll calc(ll n) {
    ll res = 0;
    for (ll i = 2; i <= n; i <<= 1) res += n / i;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1);
    return 0;
}