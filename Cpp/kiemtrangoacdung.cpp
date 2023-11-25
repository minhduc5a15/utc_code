#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool isValid(string s) {
    stack<char> stack;
    map<char, char> mapping = { {')', '('}, {'}', '{'}, {']', '['} };
    for (char& chr : s) {
        if (mapping.count(chr)) {
            char top_element = stack.empty() ? '#' : stack.top();
            stack.pop();
            if (mapping[chr] != top_element || (chr == ']' && !stack.empty() && stack.top() == '(') || (chr == '}' && !stack.empty() && stack.top() == '[') || (chr == '}' && !stack.empty() && stack.top() == '(')) {
                return false;
            }
        }
        else {
            stack.push(chr);
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
