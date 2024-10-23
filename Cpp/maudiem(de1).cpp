#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<const int, int> pcii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    vector<pii> points(n);
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
        int res = 1 << 30;
        for (const pcii &color: colors) {
            res = min(res, color.second);
        }
        for (const pcii &color: colors) {
            if (color.second == res) cout << color.first << ' ';
        }
        cout << '\n';
    }
    if (b) {
        long long res = 0;
        for (const pcii &color: colors) {
            res += color.second * (color.second - 1) / 2;
        }
        cout << res << '\n';
    }
    if (c) {
        if (k > colors.size()) cout << -1;
        else {
            set<int> color_set;
            sort(points.begin(), points.end());
            for (const pii &point: points) {
                color_set.insert(point.second);
                if (color_set.size() == k) {
                    cout << point.first;
                    break;
                }
            }
        }
    }
    return 0;
}

