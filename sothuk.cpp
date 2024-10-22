#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, k;
    cin >> n >> k;
    cout << k + (k - 1) / (n - 1);
    return 0;
}

