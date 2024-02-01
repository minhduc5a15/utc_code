#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

void print(int x, unordered_map<int, int> &map) {
    cout << x << " " << map[x] << '\n';
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
    for (const int &item: arr) {
        it = s.lower_bound(item);
        if (*it == item) {
            continue;
        }
        if (it == s.end()) {
            map[item] = map[*(--it)];
        }
        else if (it == s.begin()) {
            map[item] = map[*it];
        }
        else {
            map[item] = map[*it];
            map[item] = max(map[item], map[*(--it)]);
        }
        ++map[item];
        s.insert(item);
    }

    for_each(s.begin(), s.end(), [&map](const int &item) { print(item, map); });
    return 0;
}


