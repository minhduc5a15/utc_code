#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr;
    pair<ll, ll> sum;
    arr.reserve(n);
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        arr.emplace_back(x, y);
        sum.first += x;
        sum.second += y;
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        ll first = arr[i].first, second = arr[i].second;
        sum.first -= first;
        sum.second -= second;
        res += (n - 1) * (first * first + second * second) - 2 * (sum.first * first + sum.second * second);
    }
    cout << res << endl;
    return 0;
}
