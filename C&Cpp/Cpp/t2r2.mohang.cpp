#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int id = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        s += arr[i] * 2;
        if (s > m) {
            id = i;
            break;
        }
    }
    s -= arr[id] * 2;
    int d = arr[id] & 1;
    if (s + arr[id] * 2 <= m) {
        cout << n * 2;
    }
    else if ((s + arr[id] + arr[id] / 2 + d) <= m) {
        cout << 2 * id + 2;
    }
    else if ((s + arr[id] <= m) || (s + arr[id] / 2 + d) <= m) {
        cout << 2 * id + 1;
    }
    else cout << 2 * id;
    return 0;
}
