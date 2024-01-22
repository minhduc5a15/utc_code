#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define ll long long

using namespace std;

ll solve(const vector<ll> &arr, int n, ll k) {
    unordered_map<ll, ll> mp;
    ll max_len = 0, curr_sum = 0;
    for (int i = 0; i < n; ++i) {
        curr_sum += arr[i];
        if (curr_sum == k) max_len = i + 1;
        if (mp.find(curr_sum) == mp.end()) mp[curr_sum] = i;
        if (mp.find(curr_sum - k) != mp.end()) max_len = max(max_len, i - mp[curr_sum - k]);
    }
    return max_len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr, n, k);
    return 0;
}

