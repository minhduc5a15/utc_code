#include <iostream>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;

map<ll, ll> memo;

ll solve(ll n) {
    if (memo.find(n) != memo.end()) return memo[n];
    if (n == 0) return 0;
    ll m = log2(n);
    ll r = n - (1LL << m);
    ll result = m * (1LL << (m - 1)) + r + 1 + solve(r);
    return memo[n] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    cout << solve(n);
    return 0;
}