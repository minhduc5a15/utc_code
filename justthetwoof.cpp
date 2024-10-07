#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<ll, bool> mp;
ll n;

void test(ll num, int a, int b) {
    if (num > n) return;

    mp[num] = true;
    test(num * 10 + a, a, b);
    test(num * 10 + b, a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;

    for (int i = 0; i <= 9; ++i) {
        for (int j = i + 1; j <= 9; ++j) {
            test(i, i, j);
        }
    }

    cout << mp.size() - 1;
    return 0;
}
