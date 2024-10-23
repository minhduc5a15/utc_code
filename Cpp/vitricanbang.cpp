#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    long long sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }
    long long curr_sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        curr_sum += arr[i];
        if ((curr_sum * 2) == sum + arr[i]) {
            cout << i + 1 << ' ';
            ++count;
        }
    }
    cout << '\n' << count;
    return 0;
}
