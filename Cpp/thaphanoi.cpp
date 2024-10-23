#include <iostream>
using namespace std;

int step = 0;

void solve(int n, char a = 'A', char b = 'B', char c = 'C') {
    if (n == 1) {
        cout << "Buoc" << ++step << " Chuyen dia 1 tu " << a << " sang " << b << '\n';
        return;
    }
    else {
        solve(n - 1, a, c, b);
        cout << "Buoc" << ++step << " Chuyen dia " << n << " tu " << a << " sang " << b << '\n';
        solve(n - 1, c, b, a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    solve(n);
    return 0;
}