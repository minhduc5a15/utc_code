#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> arr) {
    int current_sum = 0, back_sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 25) {
            current_sum += arr[i];
        }
        else {
            back_sum += arr[i] - 25;
        }
    }
    if (current_sum >= back_sum) cout << "YES";
    else cout << "NO";
}

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
    solve(arr);
    return 0;
}
