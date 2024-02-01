#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long h, begin, end, n, r;
    bool check = true;
    cin >> n;
    n *= 2;
    vector<pair<int, int>> result;
    for (int i = 1; i <= trunc(sqrt(n)); ++i) {
        if (n % i) continue;
        r = n / i;
        h = r - i + 1;
        if (h & 1) continue;
        begin = h / 2;
        end = r - begin + 1;
        if (begin == end) continue;
        result.push_back(make_pair(begin, end - 1));
        check = false;
    }
    if (check) {
        cout << 0;
    }
    else {
        cout << result.size() - 1 << '\n';
    }
    for (int i = 1; i < result.size(); ++i) {
        cout << result[i].first << " " << result[i].second << '\n';
    }
    return 0;
}

