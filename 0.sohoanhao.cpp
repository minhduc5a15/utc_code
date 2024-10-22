#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        long long x;
        cin >> x;
        if (x == 6 or x == 28 or x == 496 or x == 8128 or x == 33550336 or x == 8589869056 or x == 137438691328) cout << x << " eh perfeito\n";
        else cout << x << " nao eh perfeito\n";
    }
    return 0;
}


