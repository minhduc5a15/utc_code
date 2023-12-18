#include <iostream>
#include <vector>

using namespace std;

void solve(const vector<int> &arr) {
    int current_sum = 0, back_sum = 0;
    for (const int &num: arr) {
        if (num == 25) {
            current_sum += num;
        }
        else {
            back_sum += num - 25;
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


