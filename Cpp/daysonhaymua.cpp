#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    ll res = 0;
    stack<int> st1, st2;
    vector<ll> arr(n);
    for (int i = 0; i <= n; ++i) {
        if (i != n) cin >> arr[i];
        while (!st1.empty() and (arr[st1.top()] <= arr[i] or i == n)) {
            int id = st1.top();
            st1.pop();
            res += arr[id] * (i - id) * (id - (st1.empty() ? -1 : st1.top()));
        }
        st1.push(i);
        while (!st2.empty() and (arr[st2.top()] >= arr[i] or i == n)) {
            int id = st2.top();
            st2.pop();
            res -= arr[id] * (i - id) * (id - (st2.empty() ? -1 : st2.top()));
        }
        st2.push(i);
    }
    cout << res;
    return 0;
}
