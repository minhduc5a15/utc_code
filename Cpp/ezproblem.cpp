#include <iostream>
#include <map>
#include <cmath>
std::map<int, int> prime_factors(int n) {
    std::map<int, int> factors;
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

std::string solve(int num) {
    std::map<int, int> factors = prime_factors(num);
    int coe = 1, root = 1;
    for (const auto &factor : factors) {
        int f = factor.first;
        int s = factor.second;
        int s_div_2 = s / 2;
        coe *= pow(f, s_div_2);
        if (s % 2 == 1) {
            root *= f;
        }
    }
    return std::to_string(coe) + " " + std::to_string(root);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        std::cout << solve(num) << std::endl;
    }
    return 0;
}
