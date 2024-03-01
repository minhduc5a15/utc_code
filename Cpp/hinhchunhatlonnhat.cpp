#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> matrixi;

int kadane(const vi &arr) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    for (int element : arr) {
        current_sum = max(current_sum + element, element);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int solve(const matrixi &matrix) {
    int N = matrix.size();
    int max_sum = INT_MIN;
    for (int left = 0; left < N; ++left) {
        vi temp(N, 0);
        for (int right = left; right < N; ++right) {
            for (int i = 0; i < N; ++i) {
                temp[i] += matrix[i][right];
            }
            max_sum = max(max_sum, kadane(temp));
        }
    }
    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    matrixi matrix(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << solve(matrix);
    return 0;
}

