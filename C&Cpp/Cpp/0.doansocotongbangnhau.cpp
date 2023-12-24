#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> divisors;

void divisor(int x) {
    int root = sqrt(x);
<<<<<<< Updated upstream
    if (root * root == x) arr.push_back(root);
    for (int i = 1; i < root; ++i) {
        if (x % i == 0) {
            arr.push_back(i);
            arr.push_back(x / i);
=======
    if (root * root == x) divisors.push_back(root);
    for (int i = 1; i < root; ++i) {
        if (x % i == 0) {
            divisors.push_back(i);
            divisors.push_back(x / i);
>>>>>>> Stashed changes
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
<<<<<<< Updated upstream
    int index, n;
    while (t--) {
        cin >> index >> n;
        vector<int> a(n + 1);
        int sum = 0;
        a[0] = 0;
=======
    int id, n;
    while (t--) {
        cin >> id >> n;
        vector<int> arr(n + 1);
        int sum = 0;
        arr.front() = 0;
>>>>>>> Stashed changes
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            sum += x;
<<<<<<< Updated upstream
            a[i] = sum;
        }
        int max_sum = a.back();
        divisor(max_sum);
        sort(arr.begin(), arr.end());
        int step = 0;
        for (const int &item: arr) {
=======
            arr[i] = sum;
        }
        int max_sum = arr.back();
        divisor(max_sum);
        sort(divisors.begin(), divisors.end());
        int step = 0;
        for (const int &item: divisors) {
>>>>>>> Stashed changes
            int step_arr = max_sum / item;
            int d = 0, count = 0;
            bool check;
            while (true) {
                check = false;
                for (int j = d + 1; j <= n; ++j) {
<<<<<<< Updated upstream
                    if (a[j] - a[d] == item) {
=======
                    if (arr[j] - arr[d] == item) {
>>>>>>> Stashed changes
                        check = true;
                        d = j;
                        count++;
                        break;
                    }
                }
                if (!check) break;
            }
            if (count == step_arr) {
                step = step_arr;
                break;
            }
        }
        int result = max_sum / step;
<<<<<<< Updated upstream
        if (result) cout << index << " " << result << '\n';
        else cout << index << " " << '\n';
        arr.clear();
=======
        if (result) cout << id << " " << result << '\n';
        else cout << id << " " << '\n';
        divisors.clear();
>>>>>>> Stashed changes
    }
    return 0;
}


