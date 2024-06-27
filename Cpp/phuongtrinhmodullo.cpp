#include <iostream>
#include <set>
#include <cmath>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (b - a == 0) {
        cout << "infinity\n";
        return;
    }
    int d = a - b;
    set<int> s;
    for (int i = 1; i <= sqrt(d); ++i) {
        if (d % i == 0) {
            s.insert(i);
            s.insert(d / i);
        }
    }
    int count = 0;
    for (int x: s) {
        if (a % x == b) ++count;
    }
    cout << count << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}