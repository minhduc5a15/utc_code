#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    double q = 1.0 / m;
    double result = n * ((1 - pow(q, k + 1)) / (1 - q));
    cout << fixed << setprecision(6) << result;
    return 0;
}