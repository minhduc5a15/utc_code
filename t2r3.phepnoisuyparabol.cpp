#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double x1, y1, x2, y2, x3, y3, t;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> t;
    cout << fixed << setprecision(1) << y1 * (t - x2) * (t - x3) / ((x1 - x2) * (x1 - x3)) + y2 * (t - x1) * (t - x3) / ((x2 - x1) * (x2 - x3)) + y3 * (t - x1) * (t - x2) / ((x3 - x1) * (x3 - x2));
    return 0;
}
