#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
const vector<vector<int>> faces = {{0, 3, 7, 4}, {1, 5, 6, 2}, {3, 2, 6, 7}, {0, 4, 5, 1}, {0, 1, 2, 3}, {4, 7, 6, 5}};

string rotate(const string &state, int face, bool clockwise) {
    string new_state = state;
    if (clockwise) {
        new_state[faces[face][0]] = state[faces[face][1]];
        new_state[faces[face][1]] = state[faces[face][2]];
        new_state[faces[face][2]] = state[faces[face][3]];
        new_state[faces[face][3]] = state[faces[face][0]];
        return new_state;
    }
    new_state[faces[face][0]] = state[faces[face][3]];
    new_state[faces[face][3]] = state[faces[face][2]];
    new_state[faces[face][2]] = state[faces[face][1]];
    new_state[faces[face][1]] = state[faces[face][0]];
    return new_state;
}

int bfs(const string &start, const string &goal) {
    if (start == goal) return 0;
    queue<pair<string, int>> q;
    unordered_map<string, bool> visited;
    q.push({start, 0});
    visited[start] = true;
    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();
        for (int face = 0; face < 6; ++face) {
            for (int dir = 0; dir < 2; ++dir) {
                bool clockwise = dir == 0;
                string new_state = rotate(current, face, clockwise);
                if (new_state == goal) return steps + 1;
                if (!visited.contains(new_state)) {
                    visited[new_state];
                    q.push({new_state, steps + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string start, goal;
    cin >> start >> goal;
    int res = bfs(start, goal);
    cout << res;
    return 0;
}