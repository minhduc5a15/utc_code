#include <iostream>
#include <set>
using namespace std;

int n;
string a, b;
set<string> res;

void backtrack(int i, string s) {
    if (i == n) {
        res.insert(s);
        return;
    }
    if (a[i] == b[i]) backtrack(i + 1, s + a[i]);
    backtrack(i + 1, s + a[i]);
    backtrack(i + 1, s + b[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> a >> b;
    backtrack(0, "");
    cout << res.size() << '\n';
    for (const string &s: res) {
        cout << s << '\n';
    }
    return 0;
}
