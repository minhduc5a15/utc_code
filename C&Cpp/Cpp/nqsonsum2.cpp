#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    unordered_map<int, bool> res;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (res[k - arr[i]]) cout << min(arr[i], k - arr[i]) << " " << max(arr[i], k - arr[i]) << endl;
        res[arr[i]] = true;
    }
    return 0;
}


// code by duck it1
