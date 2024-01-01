#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long res = 0;
    int left = 0, right = n - 1;
    int max_left = arr[left], max_right = arr[right];
    while (left < right) {
        if (max_left < max_right) {
            ++left;
            max_left = max(max_left, arr[left]);
            res += max_left - arr[left];
        }
        else {
            --right;
            max_right = max(max_right, arr[right]);
            res += max_right - arr[right];
        }
    }
    cout << res;
    return 0;
}
