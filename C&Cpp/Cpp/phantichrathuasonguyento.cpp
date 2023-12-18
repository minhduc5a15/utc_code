#include <iostream>
#include <map>

using namespace std;

map<int, int> prime_factors(int n) {
    map<int, int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    map<int, int> factors = prime_factors(n);
    for (const pair<const int, int> &factor: factors) {
        cout << factor.first << " " << factor.second << endl;
    }
    return 0;
}

