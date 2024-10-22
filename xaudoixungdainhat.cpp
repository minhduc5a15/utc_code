#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// manacher's algorithm
int solve(const string &s) {
    string str = "^";
    for (char c: s) {
        str += "#";
        str += c;
    }
    str += "#$";
    int n = str.size();
    vector<int> p(n, 0);
    int c = 0, r = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (r > i) {
            p[i] = min(r - i, p[2 * c - i]);
        }
        while (str[i + 1 + p[i]] == str[i - 1 - p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    return *max_element(p.begin(), p.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}

