#include <iostream>
#include <stack>
#include <string>
#define ll long long
using namespace std;

ll precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
string remove_space(const string& s) {
    string res = "";
    for (char chr: s) {
        if (chr != ' ') {
            res += chr;
        }
    }
    return res;
}
string fix(string s) {
    ll n = s.size();
    s = remove_space(s);
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '-' && !isdigit(s[i - 1])) s.insert(i, 1, '0');
    }
    return s;
}
ll calc(ll a, ll b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        break;
    }   
    return -1;
}
ll solve(string s) {
    s = fix(s);
    stack<ll> saved; stack<char> op;
    ll n = s.size();
    for (ll i = 0; i < n; ++i) {
        if (s[i] == ' ') continue;
        else if (s[i] >= '0' && s[i] <= '9') {
            ll num = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0'); i++;
            }
            saved.push(num);
            i--;
        }
        else if (s[i] == '(') {
            op.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!op.empty() && op.top() != '(') {
                ll b = saved.top(); saved.pop();
                ll a = saved.top(); saved.pop();
                char o = op.top(); op.pop();
                saved.push(calc(a, b, o));
            }
            if (!op.empty()) op.pop();
        }
        else if (s.substr(i, 3) == "abs") {
            i += 3;
            ll start = i + 1;
            ll count = 0;
            while (i < n && (s[i] != ')' || count != 0)) {
                if (s[i] == '(') ++count;
                else if (s[i] == ')') --count;
                i++;
            }
            ll num = solve(s.substr(start, i - start));
            saved.push(num > 0 ? num : -num);
            i--;
        }
        else {
            while (!op.empty() && precedence(op.top()) >= precedence(s[i])) {
                ll b = saved.top(); saved.pop();
                ll a = saved.top(); saved.pop();
                char o = op.top(); op.pop();
                saved.push(calc(a, b, o));
            }
            op.push(s[i]);
        }
    }
    while (!op.empty()) {
        ll b = saved.top(); saved.pop();
        ll a = saved.top(); saved.pop();
        char o = op.top(); op.pop();
        saved.push(calc(a, b, o));
    }
    return saved.top();
}

int main() {
    string s;
    getline(cin, s);
    cout << solve(s);
    return 0;
}
