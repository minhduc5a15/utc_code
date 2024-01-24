#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
typedef pair<ll, int> pli;

bool lambda(pli &a, pli &b) {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}

void solve(const vector<ll> &arr) {
    map<ll, int> mp;
    for (ll num: arr) {
        mp[num]++;
    }
    vector<pli> items(mp.begin(), mp.end());
    sort(items.begin(), items.end(), lambda);
    for (pli item: items) {
        cout << item.first << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    solve(arr);
    return 0;
}

