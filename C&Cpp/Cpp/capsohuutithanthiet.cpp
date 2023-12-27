#include <iostream>
#include <unordered_map>
#include <cmath>
#define pii std::pair<int, int>
#define MAXN 30
using namespace std;

struct pair_hash {
    template<class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

bool square_number(int n) {
    int k = sqrt(n);
    return k * k == n;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int solve(unordered_map<pii, int, pair_hash> &map, int exp) {
    int result = 0;
    for (const pair<const pii, int> &item: map) {
        int n = item.first.first, d = item.first.second;
        int value = map[{n, d}];
        if (exp == 1) {
            pii k = {d - n, d};
            if (map[k] && ((2 * n) != d)) {
                result += map[k] * value;
            }
        }
        else {
            int p = d * d - n * n;
            if (square_number(p)) {
                pii k = {sqrt(p), d};
                if (map[k]) {
                    result += map[k] * value;
                }
            }
        }
    }
    if (exp == 1) result += map[{1, 2}] * (map[{1, 2}] - 1);
    return result / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int size;
    cin >> size;
    unordered_map<pii, int, pair_hash> greater_map(MAXN), less_map(MAXN);
    int n, d, g;
    for (int i = 0; i < size; ++i) {
        cin >> n >> d;
        g = gcd(n, d);
        n /= g;
        d /= g;
        if (n > d) ++greater_map[{d, n}];
        else ++less_map[{n, d}];
    }
    cout << solve(greater_map, 1) + solve(less_map, 1) + solve(greater_map, 2) + solve(less_map, 2);
    return 0;
}
