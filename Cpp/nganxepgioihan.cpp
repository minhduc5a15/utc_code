#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    stack<int> s;
    size_t n, k;
    cin >> n >> k;
    while (k--) {
        string cmd;
        int x;
        cin >> cmd;
        if (cmd == "PUSH") {
            cin >> x;
            if (s.size() < n) s.push(x);
        }
        else s.pop();

    }
    while (!s.empty()) cout << s.top() << ' ', s.pop();
    return 0;
}