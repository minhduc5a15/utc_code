#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> list(int n) {
    return {n - 1, n, n + 1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ++map[arr[i]];
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    vector<vector<int>> mat;
    mat.reserve(arr.size());
    for (const int &item: arr) {
        mat.push_back(list(item));
    }
    vector<int> res;
    res.reserve(mat.size());
    for (const vector<int> &item: mat) {
        res.push_back(max(item[1] + item[2], item[1] + item[0]));
    }
    cout << *max_element(res.begin(), res.end()) << endl;
    return 0;
}

