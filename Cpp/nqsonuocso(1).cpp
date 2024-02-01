#include <iostream>
#include <cmath>

void solve(long long n) {
    int count = 0, s = 1, prime_count = 0;
    while (n % 2 == 0) {
        n /= 2;
        count++;
        prime_count = 1;
    }
    s *= count + 1;
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        count = 0;
        if (n % i == 0) {
            prime_count++;
            while (n % i == 0) {
                n /= i;
                count++;
            }
        }
        s *= count + 1;
    }
    if (n > 1) {
        prime_count++;
        s *= 2;
    }
    std::cout << s - prime_count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long long n;
    std::cin >> n;
    solve(n);
    return 0;
}

