#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll solve(ll n) {
    vll result = {n};
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            result.push_back(n);
        }
    }
    if (n > 1 and result.back() != n) {
        result.push_back(n);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vll result = solve(n);
    reverse(result.begin(), result.end());
    if (result.front() != 1) result.insert(result.begin(), 1);
    for_each(result.cbegin(), result.cend(), [](const ll &x) { cout << x << ' '; });
    return 0;
}
