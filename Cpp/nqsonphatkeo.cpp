#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define ull unsigned long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ull> arr(n);
    unordered_map<ull, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ++mp[arr[i]];
    }

    vector<pair<ull, int>> count(mp.begin(), mp.end());
    sort(count.begin(), count.end(), [](const pair<ull, int> &a, const pair<ull, int> &b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    for (pair<ull, int> item: count) {
        cout << item.first << ' ';
    }

    return 0;
}