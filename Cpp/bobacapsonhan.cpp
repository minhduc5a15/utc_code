#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

ll solve(const vector<int> &arr, int r) {
    map<ll, ll> p;
    map<ll, ll> counter;
    ll count = 0;
    for (const int &item: arr) {
        map<ll, ll>::iterator it = counter.find(item);
        if (it != counter.end()) {
            count += it->second;
        }
        it = p.find(item);
        if (it != p.end()) {
            counter[item * r] += it->second;
        }
        p[item * r]++;
    }
    return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, r;
    cin >> n >> r;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr, r);
    return 0;
}

// code by duck it1
