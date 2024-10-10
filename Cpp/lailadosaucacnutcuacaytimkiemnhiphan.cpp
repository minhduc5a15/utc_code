#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    map<int, int> mp;
    mp[arr.front()] = 0;
    for (int x: arr) {
        auto it = mp.lower_bound(x);
        if (it->first == x) continue;
        if (it == mp.end()) {
            mp[x] = (--it)->second;
        }
        else if (it == mp.begin()) {
            mp[x] = it->second;
        }
        else {
            mp[x] = it->second;
            mp[x] = max(mp[x], (--it)->second);
        }
        ++mp[x];
    }
    for (auto [k, _]: mp) {
        cout << k << ' ' << mp.at(k) << '\n';
    }
    return 0;
}