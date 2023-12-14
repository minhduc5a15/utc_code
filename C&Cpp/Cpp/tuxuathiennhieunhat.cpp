#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool lambda(const pair<string, int> &a, const pair<string, int> &b) {
    return (a.second == b.second) ? (a.first < b.first) : (a.second > b.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    unordered_map<string, int> map;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        string x;
        getline(cin, x);
        istringstream iss(x);
        string s;
        while (iss >> s) {
            ++map[s];
        }
        int k;
        cin >> k;
        vector<pair<string, int>> arr(map.begin(), map.end());
        sort(arr.begin(), arr.end(), lambda);
        for (int i = 0; i < k; ++i) {
            cout << arr[i].first << " ";
        }
        cout << "\n";
        map.clear();
    }
    return 0;
}