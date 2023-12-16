#include <iostream>
#include <vector>
using namespace std;

int solve(int n) {
    int count = 0;
    int i = 2;
    while (i * i <= n) {
        while (n % i == 0) {
            n /= i;
            ++count;
        }
        i++;
    }
    if (n > 1) ++count;
    return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}
