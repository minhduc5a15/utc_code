#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    unordered_map<int, bool> map;
    while (n--) {
        int x;
        cin >> x;
        if (map[k - x]) cout << min(x, k - x) << ' ' << max(x, k - x) << '\n';
        map[x] = true;
    }
    return 0;
}

