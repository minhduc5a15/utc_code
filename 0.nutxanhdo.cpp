#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if (a >= b) {
        cout << a - b;
    }
    else {
        int count = 0;
        while (b > a) {
            if (b & 1) {
                ++count;
                ++b;
                while (b % 2 == 0) {
                    b >>= 1;
                    ++count;
                    if (a >= b) break;
                }
            }
            else {
                while (b % 2 == 0) {
                    b >>= 1;
                    ++count;
                    if (a >= b) break;
                }
            }
        }
        cout << a - b + count;
    }
    return 0;
}
