#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<bool> visited(m + 1, false);
    priority_queue<int> h;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    visited[0] = visited[arr.front()] = visited[m] = true;
    map[arr.front()]++;
    map[m - arr.front()]++;
    h.push(arr.front());
    h.push(m - arr.front());
    cout << h.top() << " ";
    int left, right;
    for (int i = 1; i < n; ++i) {
        if (visited[arr[i]]) {
            cout << h.top() << " ";
            continue;
        }
        visited[arr[i]] = true;
        for (int j = arr[i] - 1; j >= 0; --j) {
            if (visited[j]) {
                left = arr[i] - j;
                break;
            }
        }
        for (int j = arr[i] + 1; j <= m; ++j) {
            if (visited[j]) {
                right = j - arr[i];
                break;
            }
        }
        map[right + left]--;
        map[left]++;
        map[right]++;
        h.push(left);
        h.push(right);
        while (map[h.top()] <= 0) {
            h.pop();
        }
        cout << h.top() << " ";
    }
    return 0;
}
