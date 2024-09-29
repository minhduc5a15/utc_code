#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    int min_v1 = INT_MAX, min_v2 = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
        min_v1 = min(min_v1, v1[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> v2[i];
        min_v2 = min(min_v2, v2[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += max(v1[i] - min_v1, v2[i] - min_v2);
    }
    cout << res;
    return 0;
}
