#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, x;
    unsigned long long sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sum += (x / k) * k * 3;
    }
    cout << sum;
    return 0;
}

