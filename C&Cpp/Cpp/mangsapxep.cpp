#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, arr[1001];
    cin >> n;
    string s = "YES";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    bool check = arr[0] > arr[1];
    for (int i = 1; i < n - 1; ++i) {
        if (check != (arr[i] > arr[i + 1])) {
            s = "NO";
            break;
        }
    }
    cout << s;
    return 0;
}

