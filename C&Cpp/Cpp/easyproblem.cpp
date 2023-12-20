#include <iostream>
#include <map>
#include <cmath>
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

void solve(int num) {
    map<int, int> factors = prime_factors(num);
    int coe = 1, root = 1;
    for (const pair<const int, int> &factor: factors) {
        int f = factor.first, s = factor.second;
        int s_div_2 = s / 2;
        coe *= pow(f, s_div_2);
        if (s & 1) root *= f;
    }
    cout << coe << " " << root << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        solve(num);
    }
    return 0;
}


