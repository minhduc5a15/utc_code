#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

const double PI = acos(-1);

bool check(double mid, const std::vector<int> &radii, int F) {
    int pieces = 0;
    for (const int &r: radii) {
        pieces += int(PI * r * r / mid);
    }
    return pieces >= F;
}

double solve(std::vector<int> &radii, int F) {
    double left = 0, right = PI * *std::max_element(radii.begin(), radii.end()) * *std::max_element(radii.begin(), radii.end());
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
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, f;
        std::cin >> n >> f;
        std::vector<int> pies_radii_list(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> pies_radii_list[i];
        }
        std::cout << std::fixed << std::setprecision(3) << solve(pies_radii_list, f + 1) << '\n';
    }
    return 0;
}


// code by duck it1
