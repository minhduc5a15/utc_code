#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b) {
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unordered_map<string, int> colors;
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        while (m--) {
            string color;
            cin >> color;
            ++colors[color];
        }
    }

    vector<pair<int, string>> vec;
    vec.reserve(colors.size());
    for (const pair<const string, int> &it : colors) {
        vec.emplace_back(make_pair(it.second, it.first));
    }
    sort(vec.begin(), vec.end(), compare);
    cout << vec[0].second << '\n' << vec[1].second;
    return 0;
}