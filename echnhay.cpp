#include <iostream>
#include <vector>
using namespace std;

bool solve(const vector<int> &arr, int n) {
    int max_reach = arr.front();
    for (int i = 0; i < n; ++i) {
        if (i > max_reach) return false;
        max_reach = max(max_reach, i + arr[i]);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector<int> arr;
    while (t--) {
        int n;
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        if (solve(arr, n)) cout << "True\n";
        else cout << "False\n";
    }
    return 0;
}

