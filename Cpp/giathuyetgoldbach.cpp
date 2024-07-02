#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;
vector<int> nums;

void Sieve(int n) {
    primes.resize(n, true);
    int p = 2, count = 0;
    while (p * p <= n) {
        if (primes[p]) {
            ++count;
            for (int i = p * p; i < n; i += p) {
                primes[i] = false;
            }
        }
        ++p;
    }
    primes[0] = primes[1] = false;
    nums.reserve(count * count);
    nums.emplace_back(2);
    for (int i = 3; i <= n; i += 2) {
        if (primes[i]) {
            nums.emplace_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    Sieve(n + 1);
    int count = 0;
    for (int num: nums) {
        if (num * 3 <= n) {
            for (int i = num; num + i + i <= n; ++i) {
                if (primes[i] and primes[n - num - i]) {
                    ++count;
                }
            }
        }
        else break;
    }
    cout << count;
    return 0;
}