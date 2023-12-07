#include <iostream>
using namespace std;

int solve(int n, int k) {
    if (n == 1) return 1;
    else return (solve(n - 1, k) + k - 1) % n + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}


// code by duck it1
