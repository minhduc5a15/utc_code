#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

int solve(const vi &a, const vi &b, int k, int aStart, int aEnd, int bStart, int bEnd) {
    if (aEnd < aStart) return b[k - aStart];
    if (bEnd < bStart) return a[k - bStart];
    int aMid = (aStart + aEnd) / 2, bMid = (bStart + bEnd) / 2;
    int aValue = a[aMid], bValue = b[bMid];

    if (aMid + bMid < k) {
        if (aValue > bValue) {
            return solve(a, b, k, aStart, aEnd, bMid + 1, bEnd);
        }
        return solve(a, b, k, aMid + 1, aEnd, bStart, bEnd);
    }
    if (aValue > bValue) {
        return solve(a, b, k, aStart, aMid - 1, bStart, bEnd);
    }
    return solve(a, b, k, aStart, aEnd, bStart, bMid - 1);
}

int median(const vi &a, const vi &b) {
    int na = a.size(), nb = b.size();
    int n = na + nb;
    if (n % 2) return solve(a, b, n / 2, 0, na - 1, 0, nb - 1) * 2;
    return solve(a, b, n / 2 - 1, 0, na - 1, 0, nb - 1) + solve(a, b, n / 2, 0, na - 1, 0, nb - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, q;
    cin >> m >> q;
    vector<vi> v(m + 1);
    for (int idx = 1; idx <= m; ++idx) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        v[idx] = a;
    }
    while (q--) {
        int i, j;
        cin >> i >> j;
        cout << median(v[i], v[j]) << '\n';
    }
    return 0;
}
