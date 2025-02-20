#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1.0);
constexpr int MAX_ITER = 25;
constexpr double INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        double r, xA, yA, xB, yB;
        cin >> r >> xA >> yA >> xB >> yB;
        auto f = [&](double theta) -> double {
            double xC = r * cos(theta);
            double yC = r * sin(theta);
            double dA = hypot(xA - xC, yA - yC);
            double dB = hypot(xB - xC, yB - yC);
            return dA + dB;
        };

        double best_theta = 0;
        double best_value = INF;

        double step = 2 * PI;
        for (int iter = 0; iter < MAX_ITER; ++iter) {
            double thetaL = best_theta - step;
            double thetaR = best_theta + step;
            if (thetaL < 0) thetaL += 2 * PI;
            if (thetaR >= 2 * PI) thetaR -= 2 * PI;
            double valL = f(thetaL);
            double valR = f(thetaR);
            if (valL < best_value) {
                best_value = valL;
                best_theta = thetaL;
            }
            if (valR < best_value) {
                best_value = valR;
                best_theta = thetaR;
            }
            step /= 2;
        }
        double xC = r * cos(best_theta);
        double yC = r * sin(best_theta);
        cout << fixed << setprecision(3) << xC << ' ' << yC << '\n';
    }
    return 0;
}