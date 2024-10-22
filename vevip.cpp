#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, t, x;
    cin >> n >> t;
    map<int, int> mp;
    while (n--) {
        cin >> x;
        ++mp[x];
    }
    map<int, int>::iterator it;
    while (t--) {
        cin >> x;
        it = mp.upper_bound(x);
        if (it == mp.begin()) cout << -1 << '\n';
        else {
            --it;
            --it->second;
            cout << it->first << '\n';
            if (!it->second) mp.erase(it);
        }
    }
    return 0;
}

