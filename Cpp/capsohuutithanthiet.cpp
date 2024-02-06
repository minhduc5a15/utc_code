#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;
const int MAXN = 30;

bool square_number(int n) {
    int k = sqrt(n);
    return k * k == n;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    int n, d;

    Fraction(int n, int d): n(n), d(d) {
        int g = gcd(n, d);
        this->n /= g;
        this->d /= g;
    }

    bool operator==(const Fraction &other) const {
        return n == other.n && d == other.d;
    }
};

struct FractionHash {
    size_t operator()(const Fraction &f) const {
        return hash<int>()(f.n) ^ hash<int>()(f.d);
    }
};

int solve(const unordered_map<Fraction, int, FractionHash> &map, int exp) {
    int result = 0;
    int n, d, value;
    for (const pair<const Fraction, int> &item: map) {
        n = item.first.n, d = item.first.d;
        value = map.at(Fraction(n, d));
        if (exp == 1) {
            Fraction k = Fraction(d - n, d);
            if (map.find(k) != map.end() && ((n * 2) != d)) {
                result += map.at(k) * value;
            }
        }
        else {
            int p = d * d - n * n;
            if (square_number(p)) {
                Fraction k = Fraction(sqrt(p), d);
                if (map.find(k) != map.end()) {
                    result += map.at(k) * value;
                }
            }
        }
    }
    if (exp == 1 && map.find(Fraction(1, 2)) != map.end()) result += map.at(Fraction(1, 2)) * (map.at(Fraction(1, 2)) - 1);
    return result / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int size;
    cin >> size;
    unordered_map<Fraction, int, FractionHash> greater_map(MAXN), less_map(MAXN);
    int n, d;
    for (int i = 0; i < size; ++i) {
        cin >> n >> d;
        if (n > d) ++greater_map[Fraction(d, n)];
        else ++less_map[Fraction(n, d)];
    }
    cout << solve(greater_map, 1) + solve(less_map, 1) + solve(greater_map, 2) + solve(less_map, 2);
    return 0;
}
