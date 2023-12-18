#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000000
using namespace std;

vector<int> memo(MAX + 1);


void init() {
    memo[1] = 1;
    for (int i = 2; i <= MAX; ++i) {
        long long temp = i;
        int count = 0;
        while (temp != 1 && temp >= i) {
            if (temp % 2 == 0) {
                temp /= 2;
            }
            else {
                temp = 3 * temp + 1;
            }
            ++count;
        }
        memo[i] = count + memo[temp];
    }
}

int solve(int l, int r) {
    if (l > r) swap(l, r);
    return *max_element(memo.begin() + l, memo.begin() + r + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int l, r;
    while (cin >> l >> r && (l || r)) {
        cout << l << " " << r << " " << solve(l, r) << '\n';
    }
    return 0;
}


