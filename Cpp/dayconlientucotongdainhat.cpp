#include <iostream>
#include <vector>

int kadane(std::vector<int>& list, int n) {
    int max_so_far = list[0], current_max = list[0];
    for (int i = 1; i < n; i++) {
        current_max = std::max(list[i], current_max + list[i]);
        max_so_far = std::max(current_max, max_so_far);
    }
    return max_so_far;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> list(n);
    for (int i = 0; i < n; i++) {
        std::cin >> list[i];
    }
    std::cout << kadane(list, n);
    return 0;
}