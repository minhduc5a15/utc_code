#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#define getAll(x) (x).begin(), (x).end()
typedef std::vector<int> vi;
const double PI = acos(-1);

bool check(double mid, const vi &radii, int F) {
    int pieces = 0;
    for (int r: radii) {
        pieces += int(PI * r * r / mid);
    }
    return pieces >= F;
}

double solve(const vi &radii, int F) {
    double left = 0, right = PI * *std::max_element(getAll(radii)) * *std::max_element(getAll(radii));
    while (right - left > 1e-5) {
        double mid = (left + right) / 2;
        if (check(mid, radii, F)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    std::cin >> t;
    vi pies_radii_list;
    while (t--) {
        int n, f;
        std::cin >> n >> f;
        pies_radii_list.resize(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> pies_radii_list[i];
        }
        std::cout << std::fixed << std::setprecision(3) << solve(pies_radii_list, f + 1) << '\n';
        pies_radii_list.clear();
    }
    return 0;
}

