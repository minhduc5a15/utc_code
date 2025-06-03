#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    ll res = 0;

    while (n > 0) {
        ll m = (-1 + __builtin_sqrt(1 + 8 * n)) / 2;

        ll x = (m + 1) / 2;
        res += x * x;

        n -= (m + 1) * m / 2;
    }
    cout << res;

    return 0;
}