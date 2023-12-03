#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int, int> mp_a, mp_b;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        s += mp_a[x + y]++;
        s += mp_b[1000 + x - y]++;
    }
    cout << s;
    return 0;
}

// code by duck it1
