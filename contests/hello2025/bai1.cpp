#include <iostream>
using namespace std;

void solve(const string &a, const string &b) {
    if (a.back() != b.back()) {
        if (a.back() < b.back()) {
            cout << ">\n";
            return;
        }
        cout << "<\n";
        return;
    }
    if (a.length() == b.length()) {
        cout << "=\n";
        return;
    }
    if (a.length() < b.length()) {
        cout << "<\n";
        return;
    }
    cout << ">\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    string a, b;
    while (t--) {
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}