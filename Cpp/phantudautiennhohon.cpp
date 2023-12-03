#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int size;
public:
    SegmentTree(int n) {
        size = n;
        tree.assign(2 * n, INT_MAX);
    }
    void update(int index, int value) {
        index += size;
        tree[index] = value;
        while (index > 1) {
            tree[index / 2] = min(tree[index], tree[index ^ 1]);
            index /= 2;
        }
    }
    int query(int left, int right) {
        left += size;
        right += size;
        int res = INT_MAX;
        while (left < right) {
            if (left & 1) {
                res = min(res, tree[left]);
                left++;
            }
            if (right & 1) {
                right--;
                res = min(res, tree[right]);
            }
            left /= 2;
            right /= 2;
        }
        return res;
    }
};

vector<int> solve(vector<pair<int, int>>& arr, vector<pair<int, int>>& queries) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int q = queries.size();
    SegmentTree tree(n);
    vector<int> result(q);
    int j = 0;
    for (int i = 0; i < q; ++i) {
        int x = queries[i].first, idx = queries[i].second;
        while (j < n && arr[j].first <= x) {
            tree.update(arr[j].second, arr[j].second);
            j++;
        }
        result[idx] = tree.query(0, n);
    }
    for (int& res : result) {
        res = res == INT_MAX ? -1 : res;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> arr(n), queries(q);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first;
        queries[i].second = i;
    }
    sort(queries.begin(), queries.end());
    vector<int> result = solve(arr, queries);
    for (int res : result)
        cout << res + 1 << "\n";
    return 0;
}

// code by duck it1
