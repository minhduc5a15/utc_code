#include <iostream>
#define ll long long

using namespace std;

ll count_zeros(ll x) {
    ll count = 0, i = 5;
    while (x / i > 0) {
        count += x / i;
        i *= 5;
    }
    return count;
}

ll solve(ll n) {
    ll left = 0, right = n * 5;
    while (left < right) {
        ll mid = (left + right) >> 1;
        ll count = count_zeros(mid);
        if (count < n) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}

