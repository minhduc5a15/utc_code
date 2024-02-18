#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAXN = 1000001;

vector<int> saved(MAXN);

bool check(int n) {
    map<int, int> mp;
    while (n) {
        int r = n % 10;
        n /= 10;
        mp[r]++;
        if (mp[r] == 2) return false;
    }
    return true;
}

void init() {
    for (int i = 0; i <= MAXN; ++i) {
        saved[i] = check(i);
    }
    for (int i = 1; i <= MAXN; ++i) {
        saved[i] += saved[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << saved[r] - saved[l - 1] * (l != 0) << '\n';
    }
    return 0;
}
