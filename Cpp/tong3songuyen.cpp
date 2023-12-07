#include <iostream>

using namespace std;

int solve(int N, int S) {
    int count = 0;
    for (int X = 0; X <= min(N, S); ++X) {
        int min_YZ = max(0, S - X - N);
        int max_YZ = min(N, S - X);
        if (min_YZ <= max_YZ) {
            count += max_YZ - min_YZ + 1;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, s;
    cin >> n >> s;
    cout << solve(n, s) << endl;
    return 0;
}


// code by duck it1
