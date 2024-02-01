#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, x;
    unordered_map<string, bool> map;
    int n;
    getline(cin, s);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        map[x] = true;
    }
    stringstream si(s);
    while (si >> x) {
        if (map[x]) {
            cout << string(x.size(), '*') << " ";
        }
        else {
            cout << x << " ";
        }
    }
    return 0;
}

