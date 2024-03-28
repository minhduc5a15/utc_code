#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#define ll long long
#define db double
using namespace std;

template<typename T1, typename T2> class Point {
public:
    T1 x;
    T2 y;

    Point<T1, T2>(T1 x, T2 y): x(std::move(x)), y(std::move(y)) {};

    Point(): x(), y() {};

    bool operator==(const Point<T1, T2> &other) const {
        return x == other.x and y == other.y;
    }

    bool operator!=(const Point<T1, T2> &other) const {
        return x != other.x or y != other.y;
    }

    struct Hash {
        size_t operator()(const Point<T1, T2> &p) const {
            return hash<T1>()(p.x) ^ hash<T2>()(p.y);
        }
    };
};

db getTheta(const Point<ll, ll> &A, const Point<ll, ll> &C) {
    if (A.y == C.y) return M_PI_2;
    return atan((db) (C.x - A.x) * 1.0 / (A.y - C.y) * 1.0);
}

db getEdge(const Point<ll, ll> &A, const Point<ll, ll> &C) {
    return sqrt(pow((A.x - C.x) * 1.0, 2.0) + pow((A.y - C.y) * 1.0, 2.0)) / sqrt(2);
}

Point<ll, ll> getVertex(const Point<ll, ll> &A, const Point<ll, ll> &C, char vertex) {
    db op = vertex == 'D' ? -1.0 : 1.0;
    Point<db, db> E = {(A.x + C.x) / 2.0, (A.y + C.y) / 2.0};
    db theta = getTheta(A, C);
    db cos_theta = cos(theta), sin_theta = sin(theta);
    db edge = getEdge(A, C);
    return {static_cast<ll>(round(E.x + op * edge * cos_theta / sqrt(2))), static_cast<ll>(round(E.y + op * edge * sin_theta / sqrt(2)))};
}

bool is_square(const Point<ll, ll> &A, const Point<ll, ll> &B, const Point<ll, ll> &C, const Point<ll, ll> &D) {
    if (A == B or A == C or A == D or B == C or B == D or C == D) return false;
    if ((A.x - B.x != D.x - C.x) or (A.y - B.y != D.y - C.y)) return false;
    if ((A.x - C.x) * (B.x - D.x) + (A.y - C.y) * (B.y - D.y)) return false;
    if ((A.x - D.x) * (D.x - C.x) + (A.y - D.y) * (D.y - C.y)) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<Point<ll, ll>> points(n);
    unordered_map<Point<ll, ll>, bool, Point<ll, ll>::Hash> map;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
        map[points[i]] = true;
    }
    ll count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Point<ll, ll> A = points[i];
            Point<ll, ll> C = points[j];
            if (A != C) {
                Point<ll, ll> B = getVertex(A, C, 'B');
                Point<ll, ll> D = getVertex(A, C, 'D');
                if (is_square(A, B, C, D) and map.find(B) != map.end() and map.find(D) != map.end()) ++count;
            }
        }
    }
    count >>= 1;
    cout << count << endl;
    return 0;
}
