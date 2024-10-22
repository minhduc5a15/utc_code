#include <iostream>
#include <map>
#include <cmath>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<int, int> mp;
    ull n;
    cin >> n;
    while (n % 2 == 0) {
        n >>= 1;
        ++mp[2];
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            n /= i;
            ++mp[i];
        }
    }
    if (n > 1) ++mp[n];
    int max_p = 0, count = 0;
    for (auto [_, v]: mp) {
        if (v > max_p) max_p = v;
    }
    for (int i = 2; i <= max_p; ++i) {
        int s = 0;
        for (auto [_, v]: mp) {
            if (v % i == 0) ++s;
        }
        count = max(count, s);
    }
    cout << mp.size() - count;
    return 0;
}
