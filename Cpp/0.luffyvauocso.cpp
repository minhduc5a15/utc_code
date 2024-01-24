#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const int MAXN = 1e5;

ll solve(int a, int b, const vector<ll>& arr) {
    return arr[b] - arr[a - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> arr(MAXN, 0);
    int k = 1;
    while (k < MAXN) {
        for (int i = k; i < MAXN; i += k) {
            arr[i] += k;
        }
        k += 2;
    }
    for (int i = 1; i < MAXN; ++i) {
        arr[i] += arr[i - 1];
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b, arr) << '\n';
    }
    return 0;
}
