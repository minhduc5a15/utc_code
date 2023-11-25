#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    vector<char> map(256);
    int q;
    cin >> q;
    for (char i = 'a'; i <= 'z'; ++i) {
        map[i] = i;
    }
    char c, a, b;
    while (q--) {
        cin >> c;
        if (c == 'R') {
            cin >> a >> b;
            for (char i = 'a'; i <= 'z'; ++i) {
                if (map[i] == a) {
                    map[i] = b;
                }
            }
        }
        else {
            cin >> a;
            for (char i = 'a'; i <= 'z'; ++i) {
                if (map[i] == a) {
                    map[i] = '\0';
                }
            }
        }
    }
    for (char ch : s) {
        if (map[ch] != '\0') {
            cout << map[ch];
        }
    }
    return 0;
}
