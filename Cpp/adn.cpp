#include <iostream>
#include <set>
using namespace std;

int n;
string graph, b;
set<string> res;

void backtrack(int i, string s) {
    if (i == n) {
        res.insert(s);
        return;
    }
    if (graph[i] == b[i]) backtrack(i + 1, s + graph[i]);
    backtrack(i + 1, s + graph[i]);
    backtrack(i + 1, s + b[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    cin >> graph >> b;
    backtrack(0, "");
    cout << res.size() << '\n';
    for (const string &s: res) {
        cout << s << '\n';
    }
    return 0;
}
