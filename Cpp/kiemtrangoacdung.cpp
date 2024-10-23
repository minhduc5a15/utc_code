#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool isValid(const string &s) {
    stack<char> st;
    map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
    for (char c: s) {
        if (!mp[c]) {
            st.push(c);
        }
        else {
            if (st.empty() or mp[c] != st.top()) {
                return false;
            }
            else {
                st.pop();
                if (!st.empty()) {
                    if ((c == ']' and st.top() == '(') or (c == '}' and (st.top() == '[' or st.top() == '('))) {
                        return false;
                    }
                }
            }
        }
    }
    return st.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (isValid(s)) {
            cout << "Dung\n";
        }
        else {
            cout << "Sai\n";
        }
    }
    return 0;
}