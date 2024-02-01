#include <iostream>
#include <map>
#define ll long long
using namespace std;

map<char, ll> dict = {{'M', 0}, {'A', 0}, {'R', 0}, {'C', 0}, {'H', 0}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H') {
            ++dict[s[0]];
        }
    }
    ll a = dict['M'], b = dict['A'], c = dict['R'], d = dict['C'], e = dict['H'];
    cout << a * b * (c + d + e) + c * (a + b) * (d + e) + d * e * (a + b + c);
    return 0;
}
