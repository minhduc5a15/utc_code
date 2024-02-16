#include <iostream>
#include <stack>
#include <vector>
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
    stack<int> s;
    vi pos(n, -1);
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            pos[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    vi res(n, -1);
    for (int i = 0; i < n; ++i) {
        if (pos[i] != -1) {
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
        cout << res[i] << ' ';
    }
    return 0;
}
