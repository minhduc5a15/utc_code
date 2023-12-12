#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k = sqrt(n * 2);
    k = (k & 1) ? k - 1 : k;
    cout << k;
    return 0;
}


// code by duck it1
