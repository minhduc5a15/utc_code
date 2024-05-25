#include <iostream>
#include <vector>
using namespace std;

const vector<int> prime_digits = {2, 3, 5, 7};

string solve(int k) {
    string number;
    while (k > 0) {
        int digit = (k - 1) % 4;
        k = (k - 1) / 4;
        number = to_string(prime_digits[digit]) + number;
    }
    return number;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int k;
        cin >> k;
        cout << "#" << (i + 1) << " " << solve(k) << '\n';
    }
    return 0;
}


