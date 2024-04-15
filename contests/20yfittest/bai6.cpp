#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int temp, curr, prev, n = 0, gcd = 0, sum = 0;
    cin >> prev;
    while (cin >> curr) {
        temp = abs(curr - prev);
        gcd = __gcd(gcd, temp);
        sum += temp;
        prev = curr;
        n++;
    }
    if (gcd) cout << sum / gcd - n;
    else cout << 0;
    return 0;
}

