#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<char, ll> dict = {{'M', 0}, {'A', 0}, {'R', 0}, {'C', 0}, {'H', 0}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        if (dict.find(s.front()) != dict.end()) {
            ++dict.at(s.front());
        }
    }
    ll a = dict.at('M'), b = dict.at('A'), c = dict.at('R'), d = dict.at('C'), e = dict.at('H');
    cout << a * b * (c + d + e) + c * (a + b) * (d + e) + d * e * (a + b + c);
    return 0;
}
