#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solve(const vi &arr) {
    int n = arr.size();
    vector<vi> dist(n, vi(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int diff = min(abs(arr[i] - arr[j]), 24 - abs(arr[i] - arr[j]));
            dist[i][j] = diff;
            dist[j][i] = diff;
        }
    }
    vector<pair<int, pii>> pairs(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pairs.emplace_back({dist[i][j], {i, j}});
        }
    }
    sort(pairs.begin(), pairs.end());
    vector<bool> matched(n, false);
    int result = 0;
    for (const pair<int, pii> &p: pairs) {
        int d = p.first;
        int i = p.second.first;
        int j = p.second.second;
        if (!matched[i] && !matched[j]) {
            matched[i] = true;
            matched[j] = true;
            result += d;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    return 0;
}

