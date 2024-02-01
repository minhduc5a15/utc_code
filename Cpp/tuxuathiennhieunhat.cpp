#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    unordered_map<string, int> map;
    string x;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        getline(cin, x);
        istringstream iss(x);
        string s;
        while (iss >> s) {
            ++map[s];
        }
        int k;
        cin >> k;
        vector<pair<string, int>> arr(map.begin(), map.end());
        sort(arr.begin(), arr.end(), compare);
        for (int i = 0; i < k; ++i) {
            cout << arr[i].first << " ";
        }
        cout << "\n";
        map.clear();
    }
    return 0;
}