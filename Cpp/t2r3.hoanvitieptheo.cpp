#include <iostream>
#include <algorithm>
using namespace std;

string solve(const string &s) {
    string result = s;
    int n = s.size();
    int i, j;
    for (i = n - 2; i >= 0; --i) {
        if (s[i] < s[i + 1]) break;
    }
    if (i < 0) reverse(result.begin(), result.end());
    else {
        for (j = n - 1; j > i; --j) {
            if (result[j] > result[i]) break;
        }
        swap(result[i], result[j]);
        reverse(result.begin() + i + 1, result.end());
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    string nextPerm = solve(s);
    if (nextPerm > s) cout << nextPerm;
    else cout << "KHONG CO HOAN VI TIEP THEO";
    return 0;
}
