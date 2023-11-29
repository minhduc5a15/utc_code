#include <iostream>
#include <vector>
#define ll long long

void solve(std::vector<ll>& arr) {
    ll first_max_item = arr[0];
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
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<ll> arr;
    for (int i = 0; i < n; ++i) {
        ll item;
        std::cin >> item;
        arr.push_back(item);
    }
    std::cout << arr[0] << " ";
    solve(arr);
    return 0;
}
