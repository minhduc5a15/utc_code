#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<bool>> matrix;
const vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	matrix visited(n, vector<bool>(m, false));
	matrix result(n, vector<bool>(m, false));
	result[1][1] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			visited[i][j] = (c == '.');
		}
	}
	queue<pii> q;
	q.push({1, 1});
	while (!q.empty()) {
		pii pos = q.front();
		q.pop();
		for (const vector<int> &direction: directions) {
			int nx = direction[0], ny = direction[1];
			int check = 0, i = 1;
			for (; visited[pos.first + i * nx][pos.second + i * ny]; ++i) {
				if (!result[pos.first + i * nx][pos.second + i * ny]) {
					result[pos.first + i * nx][pos.second + i * ny] = true;
					check = 1;
				}
			}
			if (check) {
				q.push({pos.first + (i - 1) * nx, pos.second + (i - 1) * ny});
			}
		}
	}
	int count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (result[i][j]) ++count;
		}
	}
	cout << count;
	return 0;
}

