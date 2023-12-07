#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int, bool> map;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (!map[x]) {
            cout << x << " ";
        }
        map[x] = true;
    }
    return 0;
}

// code by duck it1
