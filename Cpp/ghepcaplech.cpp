#include <iostream>
#include <vector>
#include <set>
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
    sort(arr.begin(), arr.end());
    if (k == 0) {
        set<int> s(arr.begin(), arr.end());
        arr.assign(s.begin(), s.end());
        n = s.size();
    }
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        int pos = upper_bound(arr.begin(), arr.end(), (k - 1) + arr[i]) - arr.begin() - 1;
        if (pos != -1 and pos > i) {
            count += (pos - i);
        }
        pos = upper_bound(arr.begin(), arr.end(), (k + 1) + arr[i]) - arr.begin() - 1;
        if (pos != -1 and pos > i) {
            count += (pos - i);
        }
    }
    cout << count;
    return 0;
}