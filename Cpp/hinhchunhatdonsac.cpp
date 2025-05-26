#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<int> pink(n), green(n);
    for (int i = 0; i < n; ++i) {
        cin >> pink[i];
        green[i] = m - pink[i];
    }
    auto solve = [](const vector<int> &arr) {
        int len = arr.size();
        ll res = 0;
        for (int i = 0; i < len; ++i) {
            int l = i, r = i;
            while (l && arr[l - 1] >= arr[i]) --l;
            while (r + 1 < len && arr[r + 1] >= arr[i]) ++r;
            res = max(res, static_cast<ll>(r - l + 1) * arr[i]);
        }
        return res;
    };
    cout << max(solve(pink), solve(green));
    return 0;
}