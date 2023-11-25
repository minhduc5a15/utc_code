#include <iostream>
#define duck int main
using namespace std;

duck() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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