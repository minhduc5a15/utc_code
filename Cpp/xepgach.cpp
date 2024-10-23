#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, float> pif;
typedef vector<int> vi;

size_t solve(vector<pif> &bricks) {
    ranges::sort(bricks, [](const pif &a, const pif &b) {
        return a.second <= b.second;
    });
    vi lis;
    for (auto [num, _]: bricks) {
        if (auto it = ranges::upper_bound(lis, num); it == lis.end()) {
            lis.push_back(num);
        }
        else *it = num;
    }

    return bricks.size() - lis.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pif> bricks(n);
    for (int i = 0; i < n; ++i) {
        cin >> bricks[i].first >> bricks[i].second;
    }
    cout << solve(bricks);
    return 0;
}
