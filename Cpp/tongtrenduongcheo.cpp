#include <iostream>
#include <vector>
typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<ll>> matrix(n, std::vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    std::vector<ll> diagonals(2 * n - 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            diagonals[i - j + n - 1] += matrix[i][j];
        }
    }
    for (const ll &sum: diagonals) {
        std::cout << sum << std::endl;
    }

    return 0;
}

