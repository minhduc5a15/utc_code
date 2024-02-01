#include <iostream>
#include <stack>
using namespace std;

string solve(const string &path) {
    stack<string> st;
    for (int i = 0; i < path.size(); ++i) {
        if (path[i] == '/') continue;
        string temp;
        while (i < path.size() && path[i] != '/') {
            temp += path[i];
            ++i;
        }
        if (temp == ".") continue;
        else if (temp == "..") {
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            st.push(temp);
        }
    }
    string res;
    while (!st.empty()) {
        res = "/" + st.top() + res;
        st.pop();
    }
    return res.empty() ? "/" : res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}