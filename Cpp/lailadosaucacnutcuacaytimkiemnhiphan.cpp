#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

void print(int x, const unordered_map<int, int> &map) {
    cout << x << " " << map.at(x) << '\n';
}
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
    unordered_map<int, int> map;
    set<int>::iterator it;
    s.insert(arr.front());
    for (int x: arr) {
        it = s.lower_bound(x);
        if (*it == x) {
            continue;
        }
        if (it == s.end()) {
            map[x] = map[*(--it)];
        }
        else if (it == s.begin()) {
            map[x] = map[*it];
        }
        else {
            map[x] = map[*it];
            map[x] = max(map[x], map[*(--it)]);
        }
        ++map[x];
        s.insert(x);
    }

    for_each(s.begin(), s.end(), [&map](const int &x) { print(x, map); });
    return 0;
}


