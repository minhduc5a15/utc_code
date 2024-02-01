#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll solve(const vector<pair<int, int>> &points, int n) {
    ll count = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int x1 = points[i].first, y1 = points[i].second;
                int x2 = points[j].first, y2 = points[j].second;
                int x3 = points[k].first, y3 = points[k].second;
                if ((y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1)) {
                    ++count;
                }
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    cout << solve(points, n);
    return 0;
}

