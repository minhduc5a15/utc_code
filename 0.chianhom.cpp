#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n, k, d, sum = 0, count = 0;

void solve(int id, int steps) {
    int s = 0;
    if (steps == k) {
        if (id == n) {
            ++count;
            return;
        }
    }
    for (int i = id; i < n; ++i) {
        s += arr[i];
        if (s == d) solve(i + 1, steps + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % k) cout << 0;
    else {
        d = sum / k;
        solve(0, 0);
        cout << count;
    }
    return 0;
}
