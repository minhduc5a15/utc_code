#include <iostream>
using namespace std;

string solve(int n, int k) {
    if (k > 9 * n) return "-1";
    if (n == 1) return to_string(k);
    string s;
    if (k > 9) return s += solve(n - 1, k - 9) + to_string(9);
    return s += solve(n - 1, 1) + to_string(k - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    return 0;
}
