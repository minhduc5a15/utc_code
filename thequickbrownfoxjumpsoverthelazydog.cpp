#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<char, bool> mp;
    string s;
    getline(cin, s);
    for (char c: s) if (c != ' ') mp[c];
    if (mp.size() < 26) cout << "false";
    else cout << "true";
    return 0;
}