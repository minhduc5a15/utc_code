#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int L, f, b, s, d, tr;
        cin >> L >> f >> b >> s >> d >> tr;
        vector<bool> traps(L + 1, false);
        while (tr--) {
            int x;
            cin >> x;
            traps[x] = true;
        }
        vector<bool> visited(L + 1, false);
        vector<int> parent(L + 1, -1);
        vector<char> mark(L + 1, 0);
        queue<int> q;

        visited[s] = true;
        q.push(s);

        auto move_f = [&](int u) {
            int v = (u + f - 1) % L + 1;
            return v;
        };
        auto move_b = [&](int u) {
            int v = (u - b - 1 + static_cast<long long>(L) * 1000) % L + 1;
            return v;
        };

        while (!q.empty() && !visited[d]) {
            int u = q.front();
            q.pop();
            if (int vB = move_b(u); !visited[vB] && !traps[vB]) {
                visited[vB] = true;
                parent[vB] = u;
                mark[vB] = 'B';
                q.push(vB);
            }
            if (int vF = move_f(u); !visited[vF] && !traps[vF]) {
                visited[vF] = true;
                parent[vF] = u;
                mark[vF] = 'F';
                q.push(vF);
            }
        }

        if (!visited[d]) {
            cout << -1 << '\n';
        }
        else {
            string res;
            for (int u = d; u != s; u = parent[u]) {
                res = mark[u] + res;
            }
            cout << res << '\n';
        }
    }

    return 0;
}
