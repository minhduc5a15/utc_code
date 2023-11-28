#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr = { 1, 2, 5, 10, 20, 25, 50 };
vector<int> root = { 100, 125, 200, 250, 500 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arr.reserve(8 * root.size() + arr.size() + 1);
    for (int i = 1; i < 8; ++i) {
        arr.insert(arr.end(), root.begin(), root.end());
        for (int& item : root) {
            item *= 10;
        }
    }
    arr.push_back(1e9);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        int count = upper_bound(arr.begin(), arr.end(), num) - arr.begin();
        cout << "#Case " << i + 1 << ": " << count << "\n";
    }
    return 0;
}
