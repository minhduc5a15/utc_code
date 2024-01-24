#include <iostream>
#include <string>
using namespace std;

string solve(const string &s) {
    int n = s.length();
    string s1, s2, result = "Just a legend";
    string t = s.substr(1, n - 2);
    for (int i = 0; i < n / 2 + 1; ++i) {
        s1 += s[i];
        s2 = s[n - i - 1] + s2;
        if (s1 == s2) {
            if (s1 + s2 == s || s1 + s2 + s[0] == s) return t;
            if (t.find(s1) != string::npos) {
                result = s1;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}

