#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Fraction {
public:
    int numerator, denominator;

    Fraction() {
        this->numerator = 0;
        this->denominator = 1;
    };

    Fraction(int n, int d) {
        this->numerator = n;
        this->denominator = d;
        if (this->denominator == 0) {
            throw invalid_argument("denominator can not be zero");
        }
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    void simplify() {
        int g = gcd(this->numerator, this->denominator);
        if (g == 1) return;
        this->numerator /= g;
        this->denominator /= g;
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    Fraction operator+(const Fraction &other) {
        int g = gcd(this->denominator, other.denominator);
        int c = this->denominator * other.denominator / g;
        int n = this->numerator * other.denominator / g + other.numerator * this->denominator / g;
        return Fraction(n, c);
    }

    Fraction operator*(const Fraction &other) {
        int n = this->numerator * other.numerator;
        int d = this->denominator * other.denominator;
        int g = gcd(n, d);
        return Fraction(n / g, d / g);
    }

    friend istream &operator>>(istream &in, Fraction &f) {
        in >> f.numerator >> f.denominator;
        if (f.denominator == 0) {
            throw invalid_argument("denominator can not be zero");
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, Fraction &f) {
        f.simplify();
        if (f.denominator == 1) {
            out << f.numerator;
            return out;
        }
        if (f.numerator == 0) {
            cout << 0;
            return out;
        }
        out << f.numerator << "/" << f.denominator;
        return out;
    }
};

int main() {
    int n;
    cout << "Nhập số phân số:\n";
    cin >> n;
    vector<Fraction> fractions(n);
    for (int i = 0; i < n; ++i) {
        cout << "Phân số thứ " << i + 1 << ": ";
        cin >> fractions[i];
        cout << '\n';
    }
    Fraction sum;

    for (int i = 0; i < n; ++i) {
        sum = sum + fractions[i];
    }
    cout << "Tổng của n phân số đã nhập: " << sum << '\n';

    Fraction product = {1, 1};

    for (int i = 0; i < n; ++i) {
        product = product * fractions[i];
    }
    cout << "Tổng của n phân số đã nhập: " << product << '\n';
    return 0;
}
