#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int l = str.size();
        vector<int> num(l);
        for (int i = 0; i < l; ++i) {
            num[i] = str[i] - 'a' + 1;
        }

        if (l == 0) {
            cout << 0 << '\n';
            continue;
        }
        if (l == 1) {
            cout << num[0] % MOD << '\n';
            continue;
        }

        int max_sum = 26 * l;
        vector dp(2, vector(27, vector<ll>(max_sum + 1, 0)));
        for (int d = 1; d <= num[0]; ++d) {
            int tight = (d == num[0]) ? 1 : 0;
            dp[tight][d][d] = (dp[tight][d][d] + 1) % MOD;
        }
        for (int pos = 1; pos < l - 1; ++pos) {
            vector next(2, vector(27, vector<ll>(max_sum + 1, 0)));
            int limit = num[pos];
            for (int tight = 0; tight < 2; ++tight) {
                for (int f = 1; f <= 26; ++f) {
                    for (int s = 0; s <= max_sum; ++s) {
                        ll ways = dp[tight][f][s];
                        if (ways == 0) continue;
                        int up = (tight == 1 ? limit : 26);
                        for (int d = 1; d <= up; ++d) {
                            int new_tight = (tight == 1 && d == up) ? 1 : 0;
                            if (int ns = s + d; ns <= max_sum)
                                next[new_tight][f][ns] = (next[new_tight][f][ns] + ways) % MOD;
                        }
                    }
                }
            }
            dp.swap(next);
        }

        ll result = 0;
        for (int tight = 0; tight < 2; ++tight) {
            for (int f = 1; f <= 26; ++f) {
                for (int s = 0; s <= max_sum; ++s) {
                    ll ways = dp[tight][f][s];
                    if (ways == 0) continue;
                    int up = (tight == 1 ? num[l - 1] : 26);
                    for (int d = 1; d <= up; ++d) {
                        if (int total = s + d; total % f == 0 && total % d == 0) {
                            result = (result + ways) % MOD;
                        }
                    }
                }
            }
        }

        cout << result % MOD << '\n';
    }
    return 0;
}