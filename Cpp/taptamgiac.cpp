#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    queue<int> q;
    size_t res = 0;
    sort(arr.begin(), arr.begin() + n, greater<>());
    for (int i = 0; i < n; ++i) {
        while (q.size() > 1 && q.front() >= q.back() + arr[i]) q.pop();
        q.push(arr[i]);
        res = max(res, q.size());
    }
    if (res >= 3) cout << res;
    else cout << "Khong the tao ra day thoa man";
    return 0;
}
