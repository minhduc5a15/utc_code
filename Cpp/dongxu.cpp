#include <iostream>
using namespace std;
typedef long long ll;

void solve(ll n) {
    bool check = false;
    do {
        int count = 0;
        while (n % 2 == 0) {
            n >>= 1;
            ++count;
            check = true;
        }
        n += count;
        while (n & 1 && (!check || n >= 10)) {
            n >>= 1;
            break;
        }
    } while (n >= 10);
    cout << (n & 1 ? 'n' : 'y') << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}

