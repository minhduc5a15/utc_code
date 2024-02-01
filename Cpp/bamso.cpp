#include <iostream>
using namespace std;

int solve(const string &s) {
    int sum = 0;
    for (char c: s) {
        if (isdigit(c)) {
            sum += c - '0';
        }
    }
    while (sum >= 10) {
        int temp = 0;
        while (sum != 0) {
            temp += sum % 10;
            sum /= 10;
        }
        sum = temp;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string n;
    cin >> n;
    cout << solve(n);
    return 0;
}
