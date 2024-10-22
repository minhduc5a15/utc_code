#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> mp(MAXN, 0);
    while (n--) {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (int i = 1; i <= MAXN; ++i) {
        mp[i] += mp[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << mp[r] - mp[l - 1] << '\n';
    }
    return 0;
}
