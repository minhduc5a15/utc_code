#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b;
    cin >> a >> b;
    long count = 0;
    for (int i = 2; i <= b; ++i) {
        int c = a / (i + 1);
        if (c >= i) count += i - 1;
        else count += c;
    }
    cout << count;
    return 0;
}

