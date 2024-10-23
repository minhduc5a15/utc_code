#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int k = sqrt(n * 2);
    k = (k & 1) ? k - 1 : k;
    cout << k;
    return 0;
}

