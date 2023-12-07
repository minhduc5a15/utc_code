#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    vector<int> diff(n + 1, 0);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        diff[l] ^= 1;
        diff[r + 1] ^= 1;
    }
    int flip = 0;
    for (int i = 0; i < n; ++i) {
        flip ^= diff[i];
        s[i] = '0' + (flip ^ (s[i] - '0'));
    }
    cout << s;
    return 0;
}


// code by duck it1
