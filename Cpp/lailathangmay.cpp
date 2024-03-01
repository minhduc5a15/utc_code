#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <climits>
using namespace std;

vector<int> arr, dis;
set<int> visited;
int maxn, k, s, f;
int res = INT_MAX;

void solve() {
    visited.insert(s);
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int num: arr) {
            int x = u + num;
            if (1 <= x and x <= maxn && visited.find(x) == visited.end()) {
                visited.insert(x);
                dis[x] = dis[u] + 1;
                if (x == f) res = min(res, dis[f]);
                q.push(x);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> maxn >> k;
    dis.resize(maxn, 0);
    arr.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> arr[i];
    }
    cin >> s >> f;
    solve();
    cout << (res == INT_MAX ? -1 : res);
    return 0;
}
