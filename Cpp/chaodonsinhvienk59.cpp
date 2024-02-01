#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> right(n, -1);
    vector<int> left(n, -1);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; ++i) {
        if (right[i] == -1 && left[i] == -1) cout << -1 << ' ';
        else if (right[i] != -1 && left[i] == -1) cout << right[i] << ' ';
        else if (right[i] == -1 && left[i] != -1) cout << left[i] << ' ';
        else {
            if (right[i] - i < i - left[i]) cout << right[i] << ' ';
            else cout << left[i] << ' ';
        }
    }
    return 0;
}
