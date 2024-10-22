#include <iostream>
#include <algorithm>
using namespace std;

int count(string s) {
    int sz = s.length();
    int c = 0;
    for (int i = 1; i < sz - 1; ++i) {
        if (s[i - 1] < s[i] and s[i] > s[i + 1]) {
            ++c;
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    int res = 0;
    cin >> n >> m >> k;
    string s = string(n, 'a') + string(m, 'b') + string(k, 'c');
    while (next_permutation(s.begin(), s.end())) {
        res = max(res, count(s));
    }
    cout << res;
    return 0;
}
