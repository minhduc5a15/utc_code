#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    pair<int, int> res = {1, 1};
    for (int i = 3; i <= n; ++i) {
        if (pos[i] <= pos[i - 2]) {
            if (i & 1) ++res.first;
            else ++res.second;
        }
    }
    cout << res.first << '\n' << res.second;
    return 0;
}
