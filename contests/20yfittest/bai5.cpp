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
    long long res = 0;
    for (int num: arr) {
        if (num < arr[n - 2]) {
            res += arr[n - 2] - num;
        }
        else break;
    }
    cout << res;
    return 0;
}
