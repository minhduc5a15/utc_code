#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int res = 1, j = 1;
    for (int i = 1; i < n;) {
        while (i < n && arr[i] >= arr[i - 1]) {
            ++j;
            ++i;
        }
        while (i < n && arr[i] <= arr[i - 1]) {
            ++j;
            ++i;
        }
        res = max(res, j);
        j = 1;
    }
    cout << res;

    return 0;
}

