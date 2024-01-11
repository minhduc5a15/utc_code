#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y;
    int res = INT_MIN;
    vector<int> dp(n, INT_MIN);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (i >= x) {
            mp[dp[i - x]]++;
        }
        if (!mp.empty()) {
            dp[i] = max(a, mp.rbegin()->first + a);
        }
        else {
            dp[i] = a;
        }
        if (i >= y && i - y >= 0) {
            mp[dp[i - y]]--;
            if (mp[dp[i - y]] == 0) {
                mp.erase(dp[i - y]);
            }
        }
        res = max(dp[i], res);
    }
    cout << res;
    return 0;
}
//#include <iostream>
//#include <vector>
//#include <deque>
//#include <climits>
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    int n, x, y;
//    cin >> n >> x >> y;
//    deque<int> dq;
//    vector<int> arr(n + 1);
//    int res = INT_MIN;
//    for (int i = 1; i <= n; ++i) {
//        int num;
//        cin >> num;
//        if (i <= x) {
//            arr[i] = num;
//        }
//        else {
//            while (!dq.empty() && arr[i - x] >= arr[dq.back()]) {
//                dq.pop_back();
//            }
//            if (!dq.empty() && dq.front() < i - y) {
//                dq.pop_front();
//            }
//            dq.push_back(i - x);
//            arr[i] = max(num + arr[dq.front()], num);
//        }
//        res = max(res, arr[i]);
//    }
//    cout << res;
//    return 0;
//}
