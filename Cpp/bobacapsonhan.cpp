#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

ll solve(const vector<int> &arr, int r) {
    map<ll, ll> p, mp;
    map<ll, ll>::iterator it;
    ll count = 0;
    for (int num: arr) {
        it = mp.find(num);
        if (it != mp.end()) {
            count += it->second;
        }
        it = p.find(num);
        if (it != p.end()) {
            mp[num * r] += it->second;
        }
        p[num * r]++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr, r);
    return 0;
}

