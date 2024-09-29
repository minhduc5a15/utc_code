#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vi right(n, -1);
    vi left(n, -1);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() and arr[s.top()] < arr[i]) {
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    s = {};
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() and arr[s.top()] < arr[i]) {
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; ++i) {
        if (right[i] == -1 and left[i] == -1) cout << -1 << ' ';
        else if (right[i] != -1 and left[i] == -1) cout << right[i] << ' ';
        else if (right[i] == -1 and left[i] != -1) cout << left[i] << ' ';
        else {
            if (right[i] - i < i - left[i]) cout << right[i] << ' ';
            else cout << left[i] << ' ';
        }
    }
    return 0;
}
