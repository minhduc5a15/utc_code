#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] - k * i > 0) res += arr[i] - k * i;
        else break;
    }
    cout << res;
    return 0;
}