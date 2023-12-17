#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) { cin >> arr[i]; }
    sort(arr.begin(), arr.end());
    cout << max(arr[0] * arr[1], arr[n - 1] * arr[n - 2]);
    return 0;
}


// code by duck it1
