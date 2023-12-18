#include <iostream>
#include <vector>
#include <climits>
typedef std::vector<int> vectori;
typedef std::vector<std::vector<int>> matrixi;
using std::cin;
using std::cout;
using std::ios_base;

int kadane(const vectori &arr) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    for (const int &element : arr) {
        current_sum = std::max(current_sum + element, element);
        max_sum = std::max(max_sum, current_sum);
    }
    return max_sum;
}

int solve(const matrixi &matrix) {
    int N = matrix.size();
    int max_sum = INT_MIN;
    for (int left = 0; left < N; ++left) {
        vectori temp(N, 0);
        for (int right = left; right < N; ++right) {
            for (int i = 0; i < N; i++) {
                temp[i] += matrix[i][right];
            }
            max_sum = std::max(max_sum, kadane(temp));
        }
    }
    return max_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    matrixi matrix(n, vectori(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << solve(matrix);
    return 0;
}

