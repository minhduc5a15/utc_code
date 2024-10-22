#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

bool compare(const pii &a, const pii &b) {
    return a.second != b.second ? a.second > b.second : a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++map[x];
    }
    vector<pii> arr(map.begin(), map.end());
    sort(arr.begin(), arr.end(), compare);
    cout << arr.front().first;
    return 0;
}

