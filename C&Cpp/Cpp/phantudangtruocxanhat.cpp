#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    int max_x = x, min_x = x;
    while (--n) {
        if (x > max_x) max_x = x;
        if (x < min_x) min_x = x;
        cin >> x;
        cout << max(max_x - x, x - min_x) << ' ';
    }
    return 0;
}
