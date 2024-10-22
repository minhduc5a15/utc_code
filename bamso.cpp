#include <iostream>
using namespace std;

int solve(const string &s) {
    int sum = 0;
    for (char c: s) {
        sum += c - '0';
    }
    if (sum < 10) return sum;
    return solve(to_string(sum));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string n;
    cin >> n;
    cout << solve(n);
    return 0;
}
