#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    ull res = 0;
    for (int i = 0; i < 1 << (n - 1); ++i) {
        ull temp = 0;
        ull c = s[0] - '0';
        for (int j = 1; j < n; ++j) {
            if ((i >> (j - 1)) & 1) {
                temp += c;
                c = 0;
            }
            c = c * 10 + (s[j] - '0');
        }
        temp += c;
        res += temp;
    }
    cout << res;
    return 0;
}
