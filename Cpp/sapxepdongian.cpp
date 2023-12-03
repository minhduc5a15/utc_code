#include <iostream>
using namespace std;
void sort(int a, int b, int c) {
    int max = a > (b > c ? b : c) ? a : (b > c ? b : c);
    int min = a < (b < c ? b : c) ? a : (b < c ? b : c);
    cout << min << endl << a + b + c - max - min << endl << max << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    sort(a, b, c);
    cout << a << endl << b << endl << c << endl;
    return 0;
}

// code by duck it1
