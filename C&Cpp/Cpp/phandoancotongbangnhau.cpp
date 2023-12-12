#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> divisor(int x) {
    vector<int> arr;
    int root = sqrt(x);
    if (root * root == x) arr.push_back(root);
    for (int i = 1; i < root; ++i) {
        if (x % i == 0) {
            arr.push_back(i);
            arr.push_back(x / i);
        }
    }
    return arr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> list(n + 1);
    int sum = 0;
    list[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int item;
        cin >> item;
        sum += item;
        list[i] = sum;
    }
    int max_sum = list[n];
    vector<int> arr = divisor(max_sum);
    sort(arr.begin(), arr.end());
    int step = 0;
    size_t sz = arr.size();
    for (int i = 0; i < sz; ++i) {
        int sum_arr = arr[i], step_arr = max_sum / sum_arr, check2, d = 0, count = 0;
        while (true) {
            check2 = 0;
            for (int j = d + 1; j <= n; ++j) {
                if (list[j] - list[d] == sum_arr) {
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
            break;
        }
    }
    cout << max_sum / step;
    return 0;
}


// code by duck it1
