#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;
    int n = s.size();
    vector<int> left_mod(n);
    vector<int> right_mod(n);
    left_mod.front() = (s.front() - '0') % a;
    right_mod.front() = (s.back() - '0') % b;
    for (int i = 1; i < n; ++i) {
        left_mod[i] = (left_mod[i - 1] * 10 + (s[i] - '0')) % a;
    }
    int coe = 10;
    for (int i = n - 2; i < n; ++i) {
        right_mod[i] = (right_mod[i + 1] + (s[i] - '0') * coe) % b;
        coe = (coe * 10) % b;
    }
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (left_mod[i] == 0 and right_mod[i + 1] == 0 and s[i + 1] != '0') {
            cout << "YES\n";
            cout << s.substr(0, i + 1) << '\n' << s.substr(i + 1, n);
            found = true;
            break;
        }
    }
    if (not found) {
        cout << "NO";
    }
    return 0;
}
