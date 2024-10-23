#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

bool square_number(int n) {
    if (n <= 0) return false;
    int root = sqrt(n);
    return root * root == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int arr[3];
    for (int &i: arr) {
        cin >> i;
    }
    int min_result = INT_MAX;
    bool check = false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i != j and arr[i] != arr[j]) {
                int sum = arr[i] * arr[i] + arr[j] * arr[j];
                if (int diff = abs(arr[i] * arr[i] - arr[j] * arr[j]); square_number(sum) or square_number(diff)) {
                    int d = square_number(sum) ? sum : diff;
                    min_result = min(min_result, abs(static_cast<int>(sqrt(d)) - arr[3 - i - j]));
                    check = true;
                }
            }
        }
    }
    cout << (check ? min_result : -1) << endl;
    return 0;
}

