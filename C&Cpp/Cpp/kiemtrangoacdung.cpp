#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool isValid(const string& s) {
    stack<char> stack;
    map<char, char> mp = { {')', '('}, {'}', '{'}, {']', '['} };
    for (const char& c : s) {
        if (mp.count(c)) {
            char top_element = stack.empty() ? '#' : stack.top();
            stack.pop();
            if (mp[c] != top_element || (c == ']' && !stack.empty() && stack.top() == '(') || (c == '}' && !stack.empty() && stack.top() == '[') || (c == '}' && !stack.empty() && stack.top() == '(')) {
                return false;
            }
        }
        else {
            stack.push(c);
        }
    }
    return stack.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << (isValid(s) ? "YES" : "NO") << '\n';
    }
    return 0;
}

