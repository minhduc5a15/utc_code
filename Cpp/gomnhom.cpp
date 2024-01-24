#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int mp[101] = {};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int res = 0;
    for (int i = 0; i <= 99; ++i) {
        if (mp[i]) {
            res = max(res, mp[i] + mp[i + 1]);
        }
    }
    cout << res << endl;
    return 0;
}
