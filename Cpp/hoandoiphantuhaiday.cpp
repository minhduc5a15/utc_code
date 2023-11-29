#include <iostream>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, res = 0;
    cin >> n;
    int arr_1[n], arr_2[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr_1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr_2[i];
        res += abs(arr_1[i] - arr_2[i]);
    }
    cout << res;
    return 0;
}