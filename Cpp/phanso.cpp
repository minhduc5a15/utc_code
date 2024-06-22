#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_a[8], prefix_b[8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q, x;
    cin >> n >> q;
    for (int i: {3, 7}) {
        prefix_a[i].resize(n + 1), prefix_b[i].resize(n + 1);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        prefix_a[3][i] = prefix_a[3][i - 1] + ((x == 3 or x == 6) ? 1 : x == 9 ? 2 : 0), prefix_a[7][i] = prefix_a[7][i - 1] + (x == 7);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        prefix_b[3][i] = prefix_b[3][i - 1] + ((x == 3 or x == 6) ? 1 : x == 9 ? 2 : 0), prefix_b[7][i] = prefix_b[7][i - 1] + (x == 7);
    }
    int l, r;
    auto solve = [&]() {
        for (int j: {3, 7}) {
            if (prefix_a[j][r] - prefix_a[j][l - 1] < prefix_b[j][r] - prefix_b[j][l - 1]) {
                cout << "N\n";
                return;
            }
        }
        cout << "Y\n";
        return;
    };
    while (q--) {
        cin >> l >> r;
        solve();
    }
    return 0;
}
