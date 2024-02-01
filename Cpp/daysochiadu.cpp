#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    unordered_map<int, vector<int>> count(m);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        count[(x % m + m) % m].push_back(i + 1);
    }

    while (q--) {
        int index, value;
        cin >> index >> value;
        if (index > (int) count[value].size()) {
            cout << "-1\n";
        }
        else {
            cout << count[value][index - 1] << '\n';
        }
    }
    return 0;
}