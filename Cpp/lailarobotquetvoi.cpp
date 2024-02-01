#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> map(m, 0);
    while (n--) {
        int x, y;
        cin >> x >> y;
        map[x]++;
        map[y]--;
    }
    int s = 0, res = 0;
    for (int i = 0; i < m; ++i) {
        s += map[i];
        res += s == 0;
    }
    cout << res;
    return 0;
}
