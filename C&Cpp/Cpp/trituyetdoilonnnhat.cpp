#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<ll> negative, positive;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x < 0) {
            negative.push_back(x);
        }
        else if (x > 0) {
            positive.push_back(x);
        }
    }
    std::sort(negative.begin(), negative.end());
    std::sort(positive.begin(), positive.end(), std::greater<>());
    std::cout << std::max((negative[0] + negative[1]) * -1, positive[0] + positive[1]) << std::endl;
    return 0;
}

