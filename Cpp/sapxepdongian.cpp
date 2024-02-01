#include <iostream>

using namespace std;

void sort(int a, int b, int c) {
    int max = a > (b > c ? b : c) ? a : (b > c ? b : c);
    int min = a < (b < c ? b : c) ? a : (b < c ? b : c);
    cout << min << '\n' << a + b + c - max - min << '\n' << max << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    sort(a, b, c);
    cout << a << '\n' << b << '\n' << c << '\n';
    return 0;
}

