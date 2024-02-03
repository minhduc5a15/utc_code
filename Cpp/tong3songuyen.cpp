#include <iostream>
using namespace std;

int solve(int n, int s) {
    int count = 0;
    for (int X = 0; X <= min(n, s); ++X) {
        int min_YZ = max(0, s - X - n);
        int max_YZ = min(n, s - X);
        if (min_YZ <= max_YZ) {
            count += max_YZ - min_YZ + 1;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s;
    cin >> n >> s;
    cout << solve(n, s) << endl;
    return 0;
}
