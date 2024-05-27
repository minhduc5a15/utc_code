#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<ll> vll;

void solve(const vll &arr) {
    ll first_max_item = arr.front();
    bool check_max = false;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > first_max_item) {
            std::cout << arr[i] << " ";
            first_max_item = arr[i];
            check_max = true;
        }
    }
    if (!check_max) {
        std::cout << -1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    vll arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << arr.front() << " ";
    solve(arr);
    return 0;
}

