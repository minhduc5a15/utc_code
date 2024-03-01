#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, bool> map;
    while (n--) {
        int x;
        cin >> x;
        if (!map[x]) {
            cout << x << " ";
        }
        map[x] = true;
    }
    return 0;
}

