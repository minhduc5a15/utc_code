#include <iostream>
#include <vector>
using namespace std;

int n, m, count = 0;
vector<int> arr;
vector<bool> visited;

int factorial(int x) {
    if (x == 1) return x;
    return x * factorial(x - 1);
}

void backtrack(int i) {
    if (i >= n) return;
    visited[i] = true;
    int s = 0, cnt = 0;
    for (int j = 0; j <= i; ++j) {
        if (visited[j]) {
            cnt++;
            s += arr[j];
        }
    }
    if (s <= m) count += factorial(cnt);
    backtrack(i + 1);
    visited[i] = false;
    backtrack(i + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    arr.assign(n + 1, 0), visited.assign(n + 1, false);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    backtrack(0);
    cout << count;
    return 0;
}