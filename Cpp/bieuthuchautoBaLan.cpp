#include <iostream>
#include <map>
#include <stack>
using namespace std;

map<char, int> precedence = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'(', 0}
};

int calc(int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    string postFix;
    stack<char> operators;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            postFix += c;
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (precedence.find(c) != precedence.end()) {
            while (!operators.empty() && precedence[operators.top()] >= precedence[c]) {
                postFix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
        else if (c == ')') {
            while (operators.top() != '(') {
                postFix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
    }
    while (!operators.empty()) {
        postFix += operators.top();
        operators.pop();
    }
    cout << postFix << endl;
    stack<int> operands;
    for (char c : postFix) {
        if (c >= '0' && c <= '9') {
            operands.push(c - '0');
        }
        else {
            int k = operands.top();
            operands.pop();
            int prev = operands.top();
            operands.pop();
            operands.push(calc(prev, k, c));
        }
    }
    cout << operands.top();
    return 0;
}


// code by duck it1
