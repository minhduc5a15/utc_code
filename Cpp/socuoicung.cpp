#include <iostream>
#include <vector>
using namespace std;

int solve(int a, int b) {
    if (b == 0) {
        return 1;
    }
    vector<int> cycle = { a % 10 };
    while (true) {
        int next_digit = (cycle.back() * a) % 10;
        if (next_digit == cycle[0]) {
            break;
        }
        cycle.push_back(next_digit);
    }

    return cycle[(b - 1) % cycle.size()];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}
