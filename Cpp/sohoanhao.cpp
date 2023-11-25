#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x == 6 || x == 28 || x == 496 || x == 8128 || x == 33550336 || x == 8589869056 || x == 137438691328)
            cout << x << " eh perfeito\n";
        else
            cout << x << " nao eh perfeito\n";
    }
    return 0;
}
