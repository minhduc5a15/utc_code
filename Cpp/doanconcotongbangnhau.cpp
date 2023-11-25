#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
std::vector <int> arr;

void divisor(int x) {
    int root = std::sqrt(x);
    if (root * root == x) arr.push_back(root);
    for (int i = 1; i < root; ++i) {
        if (x % i == 0) {
            arr.push_back(i);
            arr.push_back(x / i);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    std::cin >> t;
    int index, n;
    for (int k = 1; k <= t; ++k) {
        std::cin >> index >> n;
        std::vector<int> a(n + 1);
        int sum = 0, item;
        a[0] = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> item;
            sum += item;
            a[i] = sum;
        }
        int max_sum = a[n];
        divisor(max_sum);
        std::sort(arr.begin(), arr.end());
        int check = 0, step;
        for (int i = 0; i < arr.size(); ++i) {
            int sum_arr = arr[i];
            int step_arr = max_sum / sum_arr;
            int check2 = 1, d = 0, count = 0;
            while (1) {
                check2 = 0;
                for (int j = d + 1; j <= n; j++) {
                    if (a[j] - a[d] == sum_arr) {
                        check2 = 1;
                        d = j;
                        count++;
                        break;
                    }
                }
                if (check2 == 0) break;
            }
            if (count == step_arr) {
                step = step_arr;
                check = 1;
                break;
            }
        }
        int result = max_sum / step;
        if (result) std::cout << index << " " << result << '\n';
        else std::cout << index << " " << '\n';
        arr.clear();
    }
    return 0;
}
