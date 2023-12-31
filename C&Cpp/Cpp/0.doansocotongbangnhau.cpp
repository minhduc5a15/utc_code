#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> divisors;

void divisor(int x) {
    int root = sqrt(x);
    if (root * root == x) divisors.push_back(root);
    for (int i = 1; i < root; ++i) {
        if (x % i == 0) {
            divisors.push_back(i);
            divisors.push_back(x / i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int id, n;
    while (t--) {
        cin >> id >> n;
        vector<int> arr(n + 1);
        int sum = 0;
        arr[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            sum += x;
            arr[i] = sum;
        }
        int max_sum = arr.back();
        divisor(max_sum);
        sort(divisors.begin(), divisors.end());
        int step = 0;
        for (const int &div: divisors) {
            int s = max_sum / div;
            int d = 0, count = 0;
            bool check;
            while (true) {
                check = false;
                for (int j = d + 1; j <= n; ++j) {
                    if (arr[j] - arr[d] == div) {
                        check = true;
                        d = j;
                        count++;
                        break;
                    }
                }
                if (!check) break;
            }
            if (count == s) {
                step = s;
                break;
            }
        }
        int result = max_sum / step;
        if (result) cout << id << " " << result << '\n';
        else cout << id << " " << '\n';
        divisors.clear();
    }
    return 0;
}