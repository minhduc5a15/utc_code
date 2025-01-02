#include <iostream>
#include <vector>
using namespace std;
constexpr u_int32_t MAXN = 1000001;

vector<u_int32_t> saved(MAXN, 0);

void pre() {
    u_int32_t n = 0, i = 1;
    while (i <= MAXN) {
        while (n % 3 == 0 or n % 10 == 3) ++n;
        saved[i++] = n++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    pre();
    while (t--) {
        u_int32_t k;
        cin >> k;
        cout << saved[k] << '\n';
    }
    return 0;
}