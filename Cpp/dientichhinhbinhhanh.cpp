#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double a, b;
    cin >> a >> b;
    int alpha;
    cin >> alpha;
    double c = sqrt(a * a + b * b - 2 * a * b * cos(alpha * M_PI / 180.0));
    double p = (a + b + c) / 2;
    cout << fixed << setprecision(3) << sqrt(p * (p - a) * (p - b) * (p - c)) * 2 << endl;
    return 0;
}

