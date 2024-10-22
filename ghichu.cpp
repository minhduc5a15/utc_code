#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll res = -1;
    ll min_val = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] >= min_val) {
            res = max(res, arr[i] - min_val);
        }
        min_val = min(min_val, arr[i]);
    }
    if (res == -1) cout << "HAHA";
    else cout << res;
    return 0;
}
