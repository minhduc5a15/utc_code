#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, total = 0;
    vector<int> denomination = { 500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000 };
    cin >> n;
    if (n % 1000) cout << -1;
    else {
        for (int i = 0; i < n; ++i) {
            int amount = n / denomination[i];
            if (amount > 0) {
                total += amount;
                n -= amount * denomination[i];
            }
        }
        cout << total;
    }
    return 0;
}

