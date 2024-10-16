#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<ll, bool> mp;
ll n;

void solve(int a, int b) {
    queue<ll> q;
    q.push(a);
    q.push(b);
    while (!q.empty()) {
        ll num = q.front();
        if (num > n) return;
        q.pop();
        mp[num] = true;
        q.push(num * 10 + a);
        q.push(num * 10 + b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i <= 9; ++i) {
        for (int j = i + 1; j <= 9; ++j) {
            solve(i, j);
        }
    }
    cout << mp.size() - 1;
    return 0;
}
