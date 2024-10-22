#include <iostream>
#include <queue>
using namespace std;
constexpr int N = 4;
constexpr int MAXN = 1 << (N * N);

int flip(int state, int i, int j) {
    int pos = i * N + j;
    state ^= (1 << pos);
    if (i > 0) state ^= (1 << ((i - 1) * N + j));
    if (i < N - 1) state ^= (1 << ((i + 1) * N + j));
    if (j > 0) state ^= (1 << (i * N + (j - 1)));
    if (j < N - 1) state ^= (1 << (i * N + (j + 1)));
    return state;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> pre(MAXN, -1);
    queue<int> q;
    int start_state = 0;
    pre[start_state] = 0;
    q.push(start_state);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        int steps = pre[current];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (int new_state = flip(current, i, j); pre[new_state] == -1) {
                    pre[new_state] = steps + 1;
                    q.push(new_state);
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int start = 0, goal = 0;
        for (int i = 0; i < N; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < N; ++j) {
                if (row[j] == '1') {
                    start |= (1 << (i * N + j));
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < N; ++j) {
                if (row[j] == '1') {
                    goal |= (1 << (i * N + j));
                }
            }
        }
        int target = start ^ goal;
        cout << pre[target] << '\n';
    }
    return 0;
}