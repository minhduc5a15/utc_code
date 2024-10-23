#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> res;

int n, m;
bool found = false;

void solve(int i) {
    if (found) return;
    res.push_back(i);
    if (i == n) {
        for (int num: res) {
            cout << num << ' ';
        }
        found = true;
        return;
    }
    if (i < n) return res.pop_back();
    for (int j = sqrt(i); j >= 1; --j) {
        if (i % j) continue;
        solve((j - 1) * (i / j + 1));
    }
    if (not found) res.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> n;
    solve(m);
    if (not found) cout << "Khong Sinh Ra Duoc";
    return 0;
}
