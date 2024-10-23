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
    string op;
    cin >> op;
    sort(arr.begin(), arr.end(), greater<>());
    sort(op.begin(), op.end());
    long long res = arr.front();
    for (int i = 1; i < n; ++i) {
        if (op[i - 1] == '+') res += arr[i];
        else res -= arr[i];
    }
    cout << res;
    return 0;
}