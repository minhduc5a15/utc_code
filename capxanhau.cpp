#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    unordered_map<int, deque<int>> map;
    multimap<int, int> mp;
    mp.insert({0, 0});
    for (int i = 1; i <= k; ++i) {
        if (map[arr[i]].size() >= 2) {
            mp.erase(mp.find(map[arr[i]].back() - map[arr[i]].front()));
        }
        map[arr[i]].push_back(i);
        if (map[arr[i]].size() >= 2) {
            mp.insert({map[arr[i]].back() - map[arr[i]].front(), 0});
        }
    }
    cout << (--mp.end())->first << ' ';
    for (int i = k + 1; i <= n; ++i) {
        if (map[arr[i - k]].size() >= 2) {
            mp.erase(mp.find(map[arr[i - k]].back() - map[arr[i - k]].front()));
        }
        map[arr[i - k]].pop_front();
        if (map[arr[i - k]].size() >= 2) {
            mp.insert({map[arr[i - k]].back() - map[arr[i - k]].front(), 0});
        }
        if (map[arr[i]].size() >= 2) {
            mp.erase(mp.find(map[arr[i]].back() - map[arr[i]].front()));
        }
        map[arr[i]].push_back(i);
        if (map[arr[i]].size() >= 2) {
            mp.insert({map[arr[i]].back() - map[arr[i]].front(), 0});
        }
        cout << (--mp.end())->first << ' ';
    }

    return 0;
}