#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<const int, int> pcii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    ll n;
    cin >> n;
    vector<pair<int, int>> points(n);
    map<int, int> colors;
    for (int i = 0; i < n; ++i) {
        int x, y, color;
        cin >> x >> y >> color;
        points[i] = make_pair(x * x + y * y, color);
        ++colors[color];
    }
    size_t k;
    cin >> k;
    if (a) {
        int res = 0;
        for (const pcii &color: colors) {
            res = max(res, color.second);
        }
        for (const pcii &color: colors) {
            if (color.second == res) cout << color.first << ' ';
        }
        cout << '\n';
    }
    if (b) {
        ll res = 0;
        for (const pcii &color: colors) {
            res += color.second * (color.second - 1) / 2;
        }
        cout << n * (n - 1) / 2 - res << '\n';
    }
    if (c) {
        if (k > n) cout << -1;
        else {
            sort(points.begin(), points.end());
            cout << points[k - 1].first;
        }
    }
    return 0;
}

