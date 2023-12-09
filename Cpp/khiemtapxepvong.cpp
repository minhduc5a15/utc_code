#include <iostream>
#include <vector>
#include <map>
#include <cmath>
std::vector<int> get_divisors(int n) {
    std::vector<int> divisors;
    for (int i = 1; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}
std::map<int, int> arr = { {0, 0}, {1, 1} };

long long count_ways(int n) {
    if (arr.count(n)) {
        return arr[n];
    }

    long long total = 0;
    for (int k = 1; k < n; ++k) {
        long long inner_sum = 0;
        std::vector<int> divisors = get_divisors(k);
        for (int d : divisors) {
            inner_sum += d * count_ways(d);
        }
        total += inner_sum * count_ways(n - k);
    }

    arr[n] = total / (n - 1);
    return arr[n];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::cout << count_ways(n + 1) << std::endl;
    return 0;
}


// code by duck it1
