#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct Range {
    int l, r, id;

    bool operator<(const Range &other) const {
        return l == other.l ? r > other.r : l < other.l;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<Range> ranges(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;
    }
    sort(ranges.begin(), ranges.end());
    vector<int> contains(n), contained_by(n);

    ordered_set tree;
    for (int i = 0; i < n; ++i) {
        int r = ranges[i].r, id = ranges[i].id;
        int k = tree.order_of_key({r, -1});
        contained_by[id] = i - k;
        tree.insert({r, i});
    }
    tree.clear();
    for (int i = n - 1; i >= 0; --i) {
        int r = ranges[i].r, id = ranges[i].id;
        int k = tree.order_of_key({r, n});
        contains[id] = k;
        tree.insert({r, i});
    }
    for (int num: contains) {
        cout << num << ' ';
    }
    cout << '\n';
    for (int num: contained_by) {
        cout << num << ' ';
    }

    return 0;
}