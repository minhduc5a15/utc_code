#include <iostream>
#include <string>
using namespace std;
int main() {
    string n;
    cin >> n;
    int max_chr = n[0] - '0';
    for (char c: n) {
        max_chr = max(max_chr, c - '0');
    }
    cout << max_chr;
    return 0;
}