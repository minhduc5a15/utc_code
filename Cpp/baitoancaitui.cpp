#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

vi init(const vi &arr, int n, int c) {
    vi saved(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        int s = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                s += arr[j + c];
            }
        }
        saved[i] = s;
    }
    return saved;
}


int solve(const vi &arr, int n, int s) {
    vi saved_left = init(arr, n / 2, 0);
    vi saved_right = init(arr, n - n / 2, n / 2);
    int size_left = 1 << (n / 2);
    int size_right = 1 << (n - n / 2);
    sort(saved_right.begin(), saved_right.begin() + size_right);
    int result = 0;
    for (int i = 0; i < size_left; ++i) {
        if (saved_left[i] < s) {
            int p = lower_bound(saved_right.begin(), saved_right.begin() + size_right, s - saved_left[i]) - saved_right.begin();
            if (p == size_right || saved_right[p] + saved_left[i] != s) {
                --p;
            }
            result = max(result, saved_right[p] + saved_left[i]);
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr, n, s) << endl;
    return 0;
}
