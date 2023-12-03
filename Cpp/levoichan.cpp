#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define ll long long
using namespace std;

ll solve(vector<int>& arr, int n) {
    unordered_map<int, int> map; 
    map[0] = 1;
    ll result = 0, j = 0, k = 1;
    for (int i = 1; i <= n; ++i) {
        while (j < arr[i]) {
            ++j;
            k += map[j];
        }
        while (j > arr[i]) {
            k -= map[j];
            --j;
        }
        result += k;
        ++k;
        if (map.find(arr[i]) != map.end()) {
            map[arr[i]] += 1;
        }
        else {
            map[arr[i]] = 1;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        int item;
        cin >> item;
        arr[i] = arr[i - 1] + (item & 1 ? -1 : 1);
    }
    cout << solve(arr, n);
    return 0;
}


// code by duck it1
