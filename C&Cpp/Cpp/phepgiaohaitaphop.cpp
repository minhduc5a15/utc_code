#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<int, bool> map;
    vector<int> arr;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        map[x] = true;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (map[x]) {
            arr.push_back(x);
            map[x] = false;
        }
    }
    sort(arr.begin(), arr.end());
    for_each(arr.begin(), arr.end(), [](const int &x) { cout << x << " "; });
    return 0;
}
