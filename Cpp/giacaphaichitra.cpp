#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector<int> arr;
    while (t--) {
        arr.clear();
        int n, h, m;
        cin >> n >> h >> m;
        arr.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int res = [n, h, m, &arr]() {
            sort(arr.begin(), arr.end(), greater<int>());
            int s = 0;
            for (int i = 0; i < n; ++i) {
                s += arr[i];
            }
            for (int i = 0; i < n; ++i) {
                if (arr[i] << 1 >= s) {
                    s -= arr[i];
                }
                else break;
            }
            return s * h * m;
        }();

        cout << res << "\n";
    }
    return 0;
}