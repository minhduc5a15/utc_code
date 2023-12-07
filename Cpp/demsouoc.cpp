#include <iostream>

using namespace std;

long long solve(long long n) {
    return n / 3 + n / 5 + n / 7 - n / 15 - n / 21 - n / 35 + n / 105;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        long long n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}

// code by duck it1
