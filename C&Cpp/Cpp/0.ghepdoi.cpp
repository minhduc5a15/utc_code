#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int a, b;
    std::cin >> a >> b;
    std::cout << std::min(a, b) << " " << (int) (abs(a - b) / 2);
    return 0;
}

