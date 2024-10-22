#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void solve(const vector<int> &arr, int n, int k) {
    deque<int> q(k);
    int i;
    for (i = 0; i < k; ++i) {
        while ((!q.empty()) and arr[i] >= arr[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    for (; i < n; ++i) {
        cout << arr[q.front()] << ' ';
        while ((!q.empty()) and q.front() <= i - k) {
            q.pop_front();
        }
        while ((!q.empty()) and arr[i] >= arr[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << arr[q.front()] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    solve(arr, n, k);
    return 0;
}
