#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, h;
    cin >> n >> h;
    vector<int> top(h + 1, 0), bottom(h + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i & 1) {
            ++top[x];
        }
        else {
            ++bottom[x];
        }
    }
    pair<int, int> res = {INT_MAX, 0};
    for (int i = h - 1; i >= 0; --i) {
        top[i] += top[i + 1];
        bottom[i] += bottom[i + 1];
    }
    for (int i = 1; i <= h; ++i) {
        if (bottom[i] + top[h - i + 1] == res.first) {
            ++res.second;
        }
        else if (bottom[i] + top[h - i + 1] < res.first) {
            res.second = 1;
            res.first = bottom[i] + top[h - i + 1];
        }
    }
    cout << res.first << " " << res.second;
    return 0;
}
