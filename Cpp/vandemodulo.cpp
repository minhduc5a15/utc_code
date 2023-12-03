#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;

ull multiply(ull a, ull b, ull M) {
    if (log10(a) + log10(b) < 17) return a * b % M;
    if (a > b) swap(a, b);
    ull c = sqrt(b);
    return (multiply(a * c % M, b / c, M) + multiply(a, b % c, M)) % M;
}

void solve() {
    string x;
    ull a = 0, b, M, t = 1;
    cin >> x >> b >> M;
    for (char c : x) a = (a * 10 + c - '0') % M;
    while (b) {
        if (b % 2) t = multiply(a, t, M);
        b /= 2;
        a = multiply(a, a, M);
    }
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

// code by duck it1
