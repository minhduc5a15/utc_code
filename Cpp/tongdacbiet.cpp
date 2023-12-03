#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> result;
    long long h, first_termination, end_termination, n, r;
    bool check = true;
    cin >> n;
    n *= 2;
    for (int i = 1; i <= trunc(sqrt(n)); ++i) {
        if (n % i) continue;
        r = n / i;
        h = r - i + 1;
        if (h % 2) continue;
        first_termination = h / 2;
        end_termination = r - first_termination + 1;
        if (first_termination == end_termination) continue;
        result.push_back(to_string(first_termination) + " " + to_string(end_termination - 1));
        check = false;
    }
    if (check) {
        cout << 0;
    }
    else {
        cout << result.size() - 1 << '\n';
    }
    for (int i = 1; i < result.size(); ++i) {
        cout << result[i] << '\n';
    }
    return 0;
}


// code by duck it1
