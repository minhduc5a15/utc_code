#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int left = 0, right = n - 1;
    int len = n;
    while (left < right) {
        if (arr[left] == arr[right]) {
            ++left;
            --right;
        }
        else if (arr[left] < arr[right]) {
            arr[left + 1] += arr[left];
            ++left;
            --len;
        }
        else {
            arr[right - 1] += arr[right];
            --right;
            --len;
        }
    }
    cout << len;
    return 0;
}
