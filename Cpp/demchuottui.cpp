#include <iostream>
#include <vector>
#include <algorithm>
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
    sort(arr.begin(), arr.end());
    int count = 0, m = n >> 1;
    for (int i = 0; i < m; ++i) {
        for (int j = m; j < n; ++j) {
            if (arr[j] >= arr[i] << 1) {
                ++count;
                m = j + 1;
                break;
            }
        }
    }
    cout << n - count;
    return 0;
}
