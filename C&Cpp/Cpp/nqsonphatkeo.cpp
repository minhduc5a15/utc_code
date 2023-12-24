#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using std::cin;
using std::cout;
using std::ios_base;
using std::vector;
bool lambda(std::pair<ll, int> &a, std::pair<ll, int> &b) {
    return a.second < b.second || (a.second == b.second && a.first < b.first);
}

void solve(const vector<ll> &arr) {
    std::map<ll, int> counter;
    for (const ll &item: arr) {
        counter[item]++;
    }
    vector<std::pair<ll, int>> items(counter.begin(), counter.end());
    std::sort(items.begin(), items.end(), lambda);
    for (std::pair<ll, int> item: items) {
        std::cout << item.first << ' ';
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

