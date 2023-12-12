#include <iostream>

using namespace std;

int solve(int n) {
    if (n % 2 == 0 || n % 5 == 0) return -1;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = (res * 10 + 1) % n;
        if (res == 0) return i;
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << solve(x) << '\n';
    }
    return 0;
}
