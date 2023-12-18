#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(const vector<pair<float, float>> &arr, int n) {
    vector<int> res(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i].first > arr[j].first && arr[i].second < arr[j].second) {
                res[i] = max(res[i], res[j] + 1);
            }
        }
    }
    cout << *max_element(res.begin(), res.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    vector<pair<float, float>> arr;
    while (t--) {
        int n;
        cin >> n;
        arr.reserve(n);
        for (int i = 0; i < n; ++i) {
            float first, second;
            cin >> first >> second;
            arr.emplace_back(first, second);
        }
        solve(arr, n);
        arr.clear();
    }
    return 0;
}
