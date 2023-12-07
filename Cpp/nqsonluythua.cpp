#include <iostream>
#include <vector>
#define ul unsigned long

using namespace std;

ul count(int n, int d) {
    ul count = 0;
    if (n % d) return 0UL;
    while (n % d == 0) {
        n /= d;
        ++count;
    }
    return count;
}

ul solve(const vector<int> &arr, int n, ul sum) {
    ul count_2 = 0, count_5 = 0;
    for (int i = 0; i < n; ++i) {
        ul r = sum - arr[i];
        count_2 += count(arr[i], 2) * r;
        count_5 += count(arr[i], 5) * r;
    }
    return min(count_5, count_2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    ul sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << solve(arr, n, sum);
    return 0;
}

// code by duck it1
