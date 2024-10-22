#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000001;

vector<bool> primes;
vector<int> nums(78498);

void Sieve() {
    primes.resize(MAXN, true);
    for (int p = 2; p * p <= MAXN; ++p) {
        if (primes[p]) {
            for (int i = p * p; i <= MAXN; i += p) {
                primes[i] = false;
            }
        }
    }
    primes[0] = primes[1] = false;
    nums[0] = 2;
    int id = 0;
    for (int i = 3; i <= MAXN; i += 2) {
        if (primes[i]) {
            nums[++id] = i;
        }
    }
}

void solve(int l, int r) {
    int i = lower_bound(nums.begin(), nums.end(), l) - nums.begin();
    for (; nums[i] <= r; ++i) {
        cout << nums[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Sieve();
    int n;
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        solve(l, r);
    }
    return 0;
}
