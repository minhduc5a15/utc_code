#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long

std::vector<ll> solve(ll n) {
    std::vector<ll> result = { n };
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            result.push_back(n);
        }
    }
    if (n > 1 && result.back() != n) {
        result.push_back(n);
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    ll n;
    std::cin >> n;
    std::vector<ll> result = solve(n);
    std::reverse(result.begin(), result.end());
    if (result[0] != 1) result.insert(result.begin(), 1);
    std::for_each(result.cbegin(), result.cend(), [](const ll& x) { std::cout << x << " ";});
    return 0;
}