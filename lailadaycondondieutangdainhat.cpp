#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& arr) {
    vector<int> res;
    vector<int>::iterator pos;
    for (int num : arr) {
        pos = lower_bound(res.begin(), res.end(), num);
        if (pos == res.end()) {
            res.push_back(num);
        }
        else {
            *pos = num;
        }
    }
    return res.size();
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
    cout << solve(arr);
    return 0;
}