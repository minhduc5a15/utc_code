#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> arr(n * m);
    for (int i = 0; i < n * m; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int res = 0;
    int mid = n * m / 2;
    for (int i = 0; i < n * m; ++i) {
        if (abs(arr[i] - arr[mid]) % d == 0) {
            res += abs(arr[i] - arr[mid]) / d;
        }
        else {
            cout << -1;
            return 0;
        }
    }
    cout << res;
    return 0;
}