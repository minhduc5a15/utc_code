#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr, counter(3, 0);

void solve(int i) {
    if (n % 3) {
        cout << -1;
        return;
    }
    if (i == n) {
        for (int j = 0; j < n; ++j) {
            cout << arr[j];
        }
        cout << '\n';
        return;
    }
    for (int j = 0; j <= 2; ++j) {
        if (counter[j] >= n / 3) continue;
        arr[i] = j;
        counter[j]++;
        solve(i + 1);
        counter[j]--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    arr.assign(n, 0);
    solve(0);
    return 0;
}
