#include <iostream>
#include <string>
using namespace std;

int solve(string s) {
    int sum = 0;
    for (char c : s) {
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
    string n;
    cin >> n;
    cout << solve(n);
    return 0;
}
