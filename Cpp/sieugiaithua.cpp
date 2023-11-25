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
    ll lower_bound = 0, upper_bound = n * 5;
    while (lower_bound < upper_bound) {
        ll middle = (lower_bound + upper_bound) / 2;
        ll count = count_zeros(middle);
        if (count < n) {
            lower_bound = middle + 1;
        }
        else {
            upper_bound = middle;
        }
    }
    return lower_bound;
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