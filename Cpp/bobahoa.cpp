#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    long long R = 0, G = 0, B = 0;
    for (char c : s) {
        if (c == 'R') ++R;
        else if (c == 'G') ++G;
        else ++B;
    }
    long long res = R * G * B;
    for (int j = 0; j < n; ++j) {
        for (int d = 1; j - d >= 0 && j + d < n; ++d) {
            if (int i = j - d, k = j + d; s[i] != s[j] && s[j] != s[k] && s[i] != s[k]) {
                --res;
            }
        }
    }
    cout << res;
    return 0;
}
