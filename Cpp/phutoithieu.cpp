#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll l, k;
    cin >> l >> k;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int count = 0, temp = 0;
    for (int num: arr) {
        if (num > temp) {
            ++count;
            temp = num + k - 1;
        }
    }
    cout << count;
    return 0;
}
