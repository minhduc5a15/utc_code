#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x, y, sum = 0;
    cin >> x >> y;
    if (x > y) {
        swap(x, y);
    }
    for (int i = x; i <= y; ++i) {
        if (i % 13 != 0) {
            sum += i;
        }
    }
    cout << sum << endl;

    return 0;
}
