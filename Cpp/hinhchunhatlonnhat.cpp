#include <iostream>
#include <vector>
#include <climits>
typedef std::vector<int> Vector;
typedef std::vector<std::vector<int>> Matrix;

int kadane(Vector& arr) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        current_sum = std::max(current_sum + arr[i], arr[i]);
        max_sum = std::max(max_sum, current_sum);
    }
    return max_sum;
}

int solve(Matrix& matrix) {
    int N = matrix.size();
    int max_sum = INT_MIN;
    for (int left = 0; left < N; ++left) {
        Vector temp(N, 0);
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    Matrix matrix(n, Vector(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << solve(matrix);
    return 0;
}
