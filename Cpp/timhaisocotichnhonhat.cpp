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
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int a = arr.front(), b = arr.back();
    if (a * b >= 0) {
        if (a < 0 and b < 0) cout << b * arr[n - 2];
        else cout << a * arr[1];
    }
    else cout << a * b;
    return 0;
}