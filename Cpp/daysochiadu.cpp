#include <iostream>
#include <vector>
#include <unordered_map>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, m, q;
    std::cin >> n >> m >> q;
    std::unordered_map<int, std::vector<int>> count(m);
    for (int i = 0; i < n; ++i) {
        int it;
        std::cin >> it;
        count[(it % m + m) % m].push_back(i + 1);
    }
    while (q--) {
        int index, value;
        std::cin >> index >> value;
        if (index > (int)count[value].size()) {
            std::cout << "-1" << '\n';
        }
        else {
            std::cout << count[value][index - 1] << '\n';
        }
    }
    return 0;
}
