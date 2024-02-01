#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    while (k--) {
        int p;
        cin >> p;
        n -= p - 2;
    }
    if (n == 2) cout << "YES";
    else cout << "NO";
    return 0;
}