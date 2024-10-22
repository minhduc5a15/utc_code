#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string n;
    cin >> n;
    int max_chr = n[0] - '0';
    for (char c: n) {
        max_chr = max(max_chr, c - '0');
    }
    cout << max_chr;
    return 0;
}

