#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
const int MAX_ITER = 9;
const float TOL = 1e-4;

struct Point {
    float x, y, z;

    Point(float x, float y, float z): x(x), y(y), z(z) {}
};

vector<Point> points;

float sqr(float x) {
    return x * x;
}

float df(float z) {
    float s = 0.0;
    for (const Point &point: points) {
        float x = point.x;
        float y = point.y;
        float z_i = point.z;
        s += (z - z_i) / sqrt(sqr(x) + sqr(y) + sqr(z - z_i));
    }
    return s;
}

float ddf(float z) {
    float s = 0.0;
    for (const Point &point: points) {
        float x = point.x;
        float y = point.y;
        float z_i = point.z;
        s += 1 / sqrt(sqr(x) + sqr(y) + sqr(z - z_i));
    }
    return s;
}

float newton_method(float z_init) {
    float z = z_init;
    int iter = MAX_ITER;
    while (iter--) {
        float z_new = z - df(z) / ddf(z);
        if (abs(z - z_new) < TOL) {
            break;
        }
        z = z_new;
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        points.reserve(n);
        while (n--) {
            float x, y, z;
            cin >> x >> y >> z;
            Point point = Point(x, y, z);
            points.emplace_back(point);
        }
        cout << fixed << setprecision(4) << newton_method(0) << '\n';
        points.clear();
    }
    return 0;
}