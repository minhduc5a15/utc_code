#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool lambda(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second != b.second ? a.second > b.second : a.first > b.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++map[x];
    }    
    vector<pair<int, int>> arr(map.begin(), map.end());
    sort(arr.begin(), arr.end(), lambda);
    cout << arr.front().first;
    return 0;
}