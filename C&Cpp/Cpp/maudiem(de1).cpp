#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    int n;
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
        int res = 1 << 30;
        for (const pair<const int, int> &color: colors) {
            res = min(res, color.second);
        }
        for (const pair<const int, int> &color: colors) {
            if (color.second == res) cout << color.first << " ";
        }
        cout << '\n';
    }
    if (b) {
        long long res = 0;
        for (const pair<const int, int> &color: colors) {
            res += color.second * (color.second - 1) / 2;
        }
        cout << res << '\n';
    }
    if (c) {
        if (k > colors.size()) cout << -1;
        else {
            set<int> color_set;
            sort(points.begin(), points.end());
            for (const pair<int, int> &point: points) {
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

