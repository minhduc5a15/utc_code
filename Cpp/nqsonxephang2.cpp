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
    vector<int> pos(n, -1);
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            pos[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) {
        if (pos[i] == -1) pos[i] = -1;
        else {
            bool found = false;
            for (int j = pos[i] + 1; j < n; ++j) {
                if (arr[j] > arr[i]) {
                    found = true;
                    res[i] = arr[j];
                    break;
                }
            }
            if (!found) res[i] = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    return 0;
}
