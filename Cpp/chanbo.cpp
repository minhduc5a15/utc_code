#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Fraction {
    int a, b;
    Fraction(int a, int b) : a(a), b(b) {
        int d = __gcd(abs(a), abs(b));
        this->a /= d;
        this->b /= d;
    }
    bool operator==(const Fraction& other) const {
        return a == other.a && b == other.b;
    }
};

struct Hash {
    size_t operator()(const Fraction& f) const {
        return hash<int>()(f.a) ^ (hash<int>()(f.b) << 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    unordered_set<Fraction, Hash> cows;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cows.insert(Fraction(a, b));
    }
    cout << cows.size() << endl;
    return 0;
}
