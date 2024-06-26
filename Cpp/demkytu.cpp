#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_sum(const string &s, char c) {
    vector<int> prefix(s.size());
    prefix.front() = (s.front() == c);
    for (int i = 1; i < s.size(); ++i) {
        prefix[i] = prefix[i - 1] + (s[i] == c);
    }
    return prefix;
}

int solve(const vector<int> &prefix, int a, int b) {
    return a > 1 ? prefix[b - 1] - prefix[a - 2] : prefix[b - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int t;
    cin >> t;
    vector<int> prefix[26];
    for (char c = 'a'; c <= 'z'; ++c) {
        prefix[c - 'a'] = prefix_sum(s, c);
    }
    while (t--) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        cout << solve(prefix[c - 'a'], a, b) << ' ';
    }
    return 0;
}
