#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
constexpr int MOD = 1000000007;
constexpr int MAX_SIZE = 25;

class Solution {
private:
    vll arr;
    vector<vll> first_left, second_left, first_right, second_right;

public:
    Solution() {
        arr = {};
        first_left = first_right = second_left = second_right = {};
    }

    explicit Solution(int n, vll _arr): arr(std::move(_arr)), first_left(MAX_SIZE), second_left(MAX_SIZE), first_right(MAX_SIZE), second_right(MAX_SIZE) {
        const int mid = n >> 1;
        build_left(0, 0, 0, INT_MIN, mid);
        build_right(n - 1, 0, 0, INT_MAX, mid + 1);

        for (int i = 0; i < MAX_SIZE; ++i) {
            sort(first_right[i].begin(), first_right[i].end());
            sort(second_right[i].begin(), second_right[i].end());
        }
    }

    void build_left(int i, ll s, int steps, int end, int mid) {
        if (i > mid) {
            if (end != mid) {
                first_left[steps].push_back(s);
                return;
            }
            second_left[steps].push_back(s);
            return;
        }
        build_left(i + 1, s, steps, end, mid);
        if (end < i - 1) {
            build_left(i + 1, s + arr[i], steps + 1, i, mid);
        }
    }

    void build_right(int i, ll s, int steps, int end, int mid) {
        if (i < mid) {
            if (end != mid) {
                first_right[steps].push_back(s);
                return;
            }
            second_right[steps].push_back(s);
            return;
        }
        build_right(i - 1, s, steps, end, mid);
        if (end > i + 1) {
            build_right(i - 1, s + arr[i], steps + 1, i, mid);
        }
    }

    ll solve(int m, ll s) {
        ll res = 0;
        for (int i = 0; i <= m; ++i) {
            const int j = m - i;
            for (const ll num: first_left[i]) {
                res += upper_bound(first_right[j].begin(), first_right[j].end(), s - num) - first_right[j].begin();
                res += upper_bound(second_right[j].begin(), second_right[j].end(), s - num) - second_right[j].begin();
            }
            for (const ll num: second_left[i]) {
                res += upper_bound(first_right[j].begin(), first_right[j].end(), s - num) - first_right[j].begin();
            }
        }
        return res % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    ll s;
    cin >> n >> m >> s;
    vll arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    Solution solution(n, arr);
    cout << solution.solve(m, s);
    return 0;
}