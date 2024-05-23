#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
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
    set<int> s;
    set<int>::iterator it;
    unordered_map<int, int> mp;
    s.insert(arr.front());
    for (int x: arr) {
        it = s.lower_bound(x);
        if (*it == x) continue;
        if (it == s.end()) {
            mp[x] = mp[*(--it)];
        }
        else if (it == s.begin()) {
            mp[x] = mp[*it];
        }
        else {
            mp[x] = mp[*it];
            mp[x] = max(mp[x], mp[*(--it)]);
        }
        ++mp[x];
        s.insert(x);
    }

    for (int x: s) {
        cout << x << ' ' << mp.at(x) << '\n';
    }

    return 0;
}


