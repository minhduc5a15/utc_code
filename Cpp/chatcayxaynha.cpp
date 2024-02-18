#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, l;
    cin >> n >> l;
    vector<ll> arr(n);
    ll left = 0, right = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        right = max(right, arr[i]);
    }
    while (left <= right) {
        ll mid = (left + right) >> 1;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > mid)
                sum += arr[i] - mid;
        }
        if (sum >= l) {
            count = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << count << endl;
    return 0;
}
