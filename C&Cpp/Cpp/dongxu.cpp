#include <iostream>
using namespace std;

void solve(long long n) {
    bool check = false;
    do {
        int count = 0;
        while (n % 2 == 0) {
            n /= 2;
            ++count;
            check = true;
        }
        n += count;
        while (n & 1 && (!check || n >= 10)) {
            n /= 2;
            break;
        }
    } while (n >= 10);
    cout << (n & 1 ? 'n' : 'y') << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        solve(n);
    }
    return 0;
}

