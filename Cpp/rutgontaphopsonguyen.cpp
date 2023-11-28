#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, bool> map;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (!map[arr[i]]) {
            cout << arr[i] << " ";
        }
        map[arr[i]] = true;
    }
    return 0;
}