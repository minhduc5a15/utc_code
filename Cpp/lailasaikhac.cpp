#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
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
    sort(arr.begin(), arr.end());
    ll s = 0;
    for (ll i = 0; i < n; ++i) {
        s += arr[i] * i - arr[i] * (n - i - 1);        
    }       
    cout << s;
    return 0;
}

// code by duck it1
