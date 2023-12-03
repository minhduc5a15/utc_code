#include <iostream>
#include <vector>
#define MAXN 1000000
using namespace std;

vector<bool> prime(MAXN + 1, true);

void sieve() {
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= MAXN; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= MAXN; i += p) {
                prime[i] = false;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; ++j) {
            if (prime[j]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}



// code by duck it1
