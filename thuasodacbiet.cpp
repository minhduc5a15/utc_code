#include <iostream>
#include <algorithm>
#include <vector>
#define getAll(x) (x).begin(), (x).end()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr = {1, 2, 5, 10, 20, 25, 50};
    vector<int> root = {100, 125, 200, 250, 500};
    arr.reserve(8 * root.size() + arr.size() + 1);
    for (int i = 1; i < 8; ++i) {
        arr.insert(arr.end(), getAll(root));
        for (int &item: root) {
            item *= 10;
        }
    }
    arr.push_back(1e9);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        int count = upper_bound(getAll(arr), num) - arr.begin();
        cout << "#Case " << i + 1 << ": " << count << "\n";
    }
    return 0;
}

