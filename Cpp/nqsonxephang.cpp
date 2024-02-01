#include <iostream>
#include <stack>
#include <vector>

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
    stack<int> s;
    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            res[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    return 0;
}
