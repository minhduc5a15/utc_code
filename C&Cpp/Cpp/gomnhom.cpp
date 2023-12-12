#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> list(int n) {
    return { n - 1, n, n + 1 };
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
    unordered_map<int, int> map;
    for (const int& item : arr) {
        ++map[item];
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    vector<vector<int>> arr2;
    for (const int& item : arr) {
        vector<int> arr1 = list(item);
        arr2.push_back({ map[arr1[0]], map[arr1[1]], map[arr1[2]] });
    }
    vector<int> arr3;
    for (const vector<int>& item : arr2) {
        arr3.push_back(max(item[1] + item[2], item[1] + item[0]));
    }
    cout << *max_element(arr3.begin(), arr3.end()) << endl;
    return 0;
}


// code by duck it1
