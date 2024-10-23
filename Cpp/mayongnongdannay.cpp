#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;

bool check(const vector<int> &v, int d) {
    int count = 1, f = v.front();
    for (int x: v) {
        if (x - f >= d) {
            ++count;
            f = x;
            if (count == c) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ranges::sort(arr);
    int res = 0;
    int left = 1, right = arr.back() - arr.front();
    while (left <= right) {
        if (int mid = (left + right) >> 1; check(arr, mid)) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << res;
    return 0;
}