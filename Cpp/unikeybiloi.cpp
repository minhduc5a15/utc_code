#include <iostream>
using namespace std;

void solve(const string &s) {
    string res;
    for (char c: s) {
        if (c == '@' or c == '#' or c == '$' or c == '%') {
            res += c;
        }
        else cout << c;
    }
    cout << res << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, temp;
    getline(cin, s);
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        temp.clear();
        while (i < n and s[i] != ' ') {
            temp += s[i];
            ++i;
        }
        solve(temp);
    }
    return 0;
}
