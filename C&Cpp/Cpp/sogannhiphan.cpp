#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string n;
    cin >> n;
    int max_chr = n[0] - '0';
    for (const char &c: n) {
        max_chr = max(max_chr, c - '0');
    }
    cout << max_chr;
    return 0;
}

