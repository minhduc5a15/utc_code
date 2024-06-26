#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int solve(const vector<int> &arr) {
    int result = INT_MAX;
    for (int k = *min_element(arr.begin(), arr.end()); k <= *max_element(arr.begin(), arr.end()); ++k) {
        int diffSum = 0;
        for (int num: arr) {
            diffSum += abs(num - k);
        }
        result = min(result, diffSum);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    return 0;
}
