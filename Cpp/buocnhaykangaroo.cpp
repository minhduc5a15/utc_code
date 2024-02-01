#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    deque<int> dq;
    vector<int> arr(n + 1);
    int res = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        if (i <= x) {
            arr[i] = num;
        }
        else {
            while (!dq.empty() && arr[i - x] >= arr[dq.back()]) {
                dq.pop_back();
            }
            if (!dq.empty() && dq.front() < i - y) {
                dq.pop_front();
            }
            dq.push_back(i - x);
            arr[i] = max(num + arr[dq.front()], num);
        }
        res = max(res, arr[i]);
    }
    cout << res;
    return 0;
}
