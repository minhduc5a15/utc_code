#include <iostream>
#include <vector>
using namespace std;

bool check(int a, int b) {
    return (a + b) % 4 == 0;
}

void solve(int n, vector<int> &arr, vector<bool> &saved, int &res, int index) {
    if (index == n) {
        bool c = true;
        for (int i = 1; i < n; ++i) {
            if (check(arr[i - 1], arr[i])) {
                c = false;
                break;
            }
        }
        if (c) {
            for (int i = 0; i < n; ++i) {
                cout << arr[i] << ' ';
            }
            cout << '\n';
            ++res;
        }
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!saved[i]) {
            arr[index] = i;
            saved[i] = true;
            solve(n, arr, saved, res, index + 1);
            saved[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<bool> saved(n + 1, false);
    int res = 0;
    solve(n, arr, saved, res, 0);
    cout << res;
    return 0;
}
