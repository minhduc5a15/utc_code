#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

void solve(int s, int f) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;
    h.push({ 0, s });
    set<int> visited;
    while (!h.empty()) {
        int res = h.top().first;
        int n = h.top().second;
        h.pop();
        if (n == f) {
            cout << res << '\n';
            return;
        }
        if (visited.count(n)) {
            continue;
        }
        visited.insert(n);
        for (int a = 1; a <= static_cast<int>(sqrt(n)); ++a) {
            if (n % a == 0) {
                int b = n / a;
                int m = (a - 1) * (b + 1);
                int new_cost = res + ((b % a == 0) ? (b / a) : (a + b));
                h.push({ new_cost, m });
            }
        }
    }
    cout << -1 << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int s, f;
        cin >> s >> f;
        solve(s, f);
    }
    return 0;
}
