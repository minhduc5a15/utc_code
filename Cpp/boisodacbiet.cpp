#include <iostream>
#include <queue>
#define ll long long
using namespace std;

void solve(int n) {
    queue<ll> q;
    q.push(9);
    while (!q.empty()) {
        ll num = q.front();
        q.pop();
        if (num % n == 0) {
            cout << num << '\n';
            return;
        }
        q.push(num * 10);
        q.push(num * 10 + 9);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}