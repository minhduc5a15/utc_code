#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i + 1] and arr[i + 2]) {
            cout << "khong qua duoc suoi";
            return 0;
        }
        i += !arr[i + 2];
        ++res;
    }
    cout << res;
    return 0;
}
