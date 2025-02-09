#include <iostream>
using namespace std;

int mod_string(const string &s, int n) {
    int r = 0;
    for (char c: s) {
        r = (r * 10 + (c - '0')) % n;
    }
    return r;
}

int mod_power(int base, int exp, int mod) {
    int res = 1;
    for (int i = 0; i < exp; ++i) {
        res = (res * base) % mod;
    }
    return res;
}

bool solve(const string &s, int n) {
    int len = s.length();
    int r = mod_string(s, n);
    if (r == 0) return true;

    int p = mod_power(10, len - 1, n);

    for (int i = 0; i < len - 1; ++i) {
        int c = s[i] - '0';
        r = ((r - c * p) * 10 + c) % n;
        if (r < 0) r += n;
        if (r == 0) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> s >> n;
        cout << (solve(s, n) ? 'Y' : 'N') << '\n';
    }
    return 0;
}
