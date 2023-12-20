#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dist(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int diff = min(abs(arr[i] - arr[j]), 24 - abs(arr[i] - arr[j]));
            dist[i][j] = diff;
            dist[j][i] = diff;
        }
    }
    vector<pair<int, pair<int, int>>> pairs;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pairs.push_back({dist[i][j], {i, j}});
        }
    }
    sort(pairs.begin(), pairs.end());
    vector<bool> matched(n, false);
    int result = 0;
    for (const pair<int, pair<int, int>> &p: pairs) {
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
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    return 0;
}

