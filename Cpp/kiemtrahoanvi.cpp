#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n;
    m = n;
    unordered_map<int, bool> mp;
    bool check = true;
    while (n--) {
        int x;
        cin >> x;
        if (x > m || mp[x] || x < 1) {
            cout << "NO";
            check = false;
            break;
        }
        mp[x] = true;
    }
    if (check) {
        cout << "YES";
    }
    return 0;
}
