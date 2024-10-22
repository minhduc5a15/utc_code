#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = n; i >= 1; --i) {
        if (sum % i == 0) {
            int s = 0, t = sum / i;
            for (int x: arr) {
                s += x;
                if (s == t) s = 0;
            }
            if (s == 0) {
                cout << t;
                break;
            }
        }
    }
    return 0;
}
