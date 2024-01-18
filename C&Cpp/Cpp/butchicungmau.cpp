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
    int count = 1, max_l = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] == arr[i + 1]) ++count;
        else {
            count = 1;
        }
        max_l = max(max_l, count);
    }
    cout << n - max_l << endl;
    return 0;
}
