#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
constexpr int MAXN = 1000001;

vector<bool> prime(MAXN, true);

void Sieve() {
    for (int i = 2; i <= sqrt(MAXN); ++i) {
        if (prime[i]) {
            for (int p = i * i; p < MAXN; p += i) {
                prime[p] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Sieve();
    vector<int> arr(MAXN, 0);
    for (int i = 2; i < MAXN; ++i) {
        if (prime[i]) {
            for (int p = i; p < MAXN; p += i) {
                ++arr[p];
            }
        }
    }
    int n, x, count = 0, res = 0;
    cin >> n;
    while (n--) {
        cin >> x;
        if (count < arr[x]) {
            count = arr[x];
            res = x;
        }
    }
    cout << res;
    return 0;
}
