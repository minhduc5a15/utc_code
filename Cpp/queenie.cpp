#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

const vector<int> dq = {1, -1, 0, 0, 1, -1};
const vector<int> dr = {0, 0, 1, -1, -1, 1};

struct coord {
    int q, r;
};

struct pair_hash {
    size_t operator()(const pair<int, int> &p) const {
        return (static_cast<unsigned long long>(p.first) << 32) ^ static_cast<unsigned long long>(p.second);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int R, K;
    cin >> R >> K;
    int N = R * R * R - (R - 1) * (R - 1) * (R - 1);

    unordered_map<pair<int, int>, int, pair_hash> coord_to_idx;
    coord_to_idx.reserve(N << 1);

    vector<coord> idx_to_coord(N + 1);
    int idx = 0;
    for (int r = -(R - 1); r <= (R - 1); ++r) {
        int q_min = max(-(R - 1), -r - (R - 1));
        int q_max = min((R - 1), -r + (R - 1));
        for (int q = q_min; q <= q_max; ++q) {
            idx++;
            coord_to_idx[{q, r}] = idx;
            idx_to_coord[idx] = {q, r};
        }
    }

    vector<bool> check(N + 1, false);
    for (int i = 0; i < K; ++i) {
        int x;
        cin >> x;
        check[x] = true;
    }

    vector<bool> empty(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!check[i]) empty[i] = true;
    }

    vector<bool> reachable(N + 1, false);
    queue<int> q_empty;

    for (int i = 1; i <= N; ++i) {
        if (!empty[i]) continue;
        int q = idx_to_coord[i].q, r = idx_to_coord[i].r;
        bool on_border = false;
        for (int dir = 0; dir < 6; ++dir) {
            int nq = q + dq[dir];
            int nr = r + dr[dir];
            if (coord_to_idx.find({nq, nr}) == coord_to_idx.end()) {
                on_border = true;
                break;
            }
        }
        if (on_border) {
            reachable[i] = true;
            q_empty.push(i);
        }
    }

    while (!q_empty.empty()) {
        int u = q_empty.front();
        q_empty.pop();
        int q = idx_to_coord[u].q, r = idx_to_coord[u].r;
        for (int dir = 0; dir < 6; ++dir) {
            int nq = q + dq[dir];
            int nr = r + dr[dir];
            auto it = coord_to_idx.find({nq, nr});
            if (it == coord_to_idx.end()) continue;
            int v = it->second;
            if (empty[v] && !reachable[v]) {
                reachable[v] = true;
                q_empty.push(v);
            }
        }
    }

    vector<bool> visited(N + 1, false);
    long long res = 0;
    queue<int> q_bfs;

    for (int start = 1; start <= N; start++) {
        if (!check[start] || visited[start]) continue;
        visited[start] = true;
        q_bfs.push(start);

        while (!q_bfs.empty()) {
            int u = q_bfs.front();
            q_bfs.pop();
            int q = idx_to_coord[u].q, r = idx_to_coord[u].r;

            for (int dir = 0; dir < 6; ++dir) {
                int q1 = q + dq[dir];
                int r1 = r + dr[dir];
                auto it = coord_to_idx.find({q1, r1});
                if (it == coord_to_idx.end()) {
                    res++;
                }
                else {
                    int v = it->second;
                    if (check[v]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q_bfs.push(v);
                        }
                    }
                    else {
                        if (reachable[v]) {
                            res++;
                        }
                    }
                }
            }
        }
    }

    cout << res;
    return 0;
}
