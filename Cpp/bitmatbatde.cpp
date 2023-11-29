#include <iostream>
using namespace std;

int solve(int n, int k) {
    if (n == 1) return 1;
    else return (solve(n - 1, k) + k - 1) % n + 1;
}
int main() {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}
