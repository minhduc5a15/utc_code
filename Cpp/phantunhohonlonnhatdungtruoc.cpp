#include <iostream>
#include <vector>
#include <map>

void solve(std::vector<int>& arr, int n) {
    std::map<int, int> map;
    for (int i = 0; i < n; ++i) {
        auto it = map.lower_bound(arr[i]);
        if (it == map.begin()) {
            std::cout << "0" << '\n';
        }
        else {
            --it;
            std::cout << it->first << " " << it->second << '\n';
        }
        map[arr[i]]++;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    solve(arr, n);
    return 0;
}
