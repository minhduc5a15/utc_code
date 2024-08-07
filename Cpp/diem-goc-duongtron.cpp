#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double distance(int x, int y) {
    return sqrt(x * x + y * y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, n;
    cin >> r >> n;
    double max_distance = -1;
    bool check = false;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        if (distance(arr[i].first, arr[i].second) <= r) {
            max_distance = max(max_distance, distance(arr[i].first, arr[i].second));
            check = true;
        }
    }
    if (!check) {
        cout << 0;
    }
    else {
        for (const pair<int, int> &item: arr) {
            if (distance(item.first, item.second) == max_distance) {
                cout << item.first << ' ' << item.second << '\n';
                break;
            }
        }
    }
    return 0;
}

