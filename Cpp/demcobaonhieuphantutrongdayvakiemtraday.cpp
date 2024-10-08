#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, c, d, count = 0;
    cin >> n;
    cin >> c >> d;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] >= -c and arr[i] <= d) ++count;
    }
    cout << count << '\n';
    if (bool check = arr[0] < arr[1]; !check) cout << "NO";
    else {
        for (int i = 2; i < n - 1; ++i) {
            if (check != arr[i] < arr[i + 1]) {
                check = false;
                cout << "NO";
                break;
            }
        }
        if (check) cout << "YES";
    }
    return 0;
}
