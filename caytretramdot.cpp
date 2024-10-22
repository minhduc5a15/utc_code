#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0, c1 = 0, c2 = 0;
    while (n--) {
        int x;
        cin >> x;
        sum += x;
        if (x & 1) ++c1;
        else ++c2;
    }
    int d = abs(c1 - c2) - 1;
    cout << sum - d;
    return 0;
}
