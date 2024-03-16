#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1000000;

vector<int> saved(MAXN + 1);

void init() {
    saved[1] = 1;
    for (int i = 2; i <= MAXN; ++i) {
        long long temp = i;
        int count = 0;
        while (temp != 1 && temp >= i) {
            if (temp % 2 == 0) {
                temp >>= 1;
            }
            else {
                temp = 3 * temp + 1;
            }
            ++count;
        }
        saved[i] = count + saved[temp];
    }
}

int solve(int l, int r) {
    if (l > r) swap(l, r);
    return *max_element(saved.begin() + l, saved.begin() + r + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int l, r;
    while (cin >> l >> r && (l || r)) {
        cout << l << " " << r << " " << solve(l, r) << '\n';
    }
    return 0;
}


