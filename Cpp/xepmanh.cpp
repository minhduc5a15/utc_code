#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    int count = 0;
    if (b >= 4) {
        count += 2 * (b / 4);
        b -= (count / 2) * 4;
        a -= (count / 2) * 4;
    }
    if (b > 0 && a >= 3) count += 1;
    cout << count << endl;

    return 0;
}
