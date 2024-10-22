#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int count = 0, flag = 0, max_n = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x) {
            ++count;
            --flag;
        }
        else ++flag;
        flag = max(flag, 0);
        max_n = max(flag, max_n);
    }
    cout << (count == n ? --count : count + max_n);
    return 0;
}