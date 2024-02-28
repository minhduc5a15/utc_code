#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    float x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) cout << "Origem";
    else if (x == 0 && y != 0) cout << "Eixo Y";
    else if (x != 0 && y == 0) cout << "Eixo X";
    else if (x > 0 && y > 0) cout << "Q1";
    else if (x < 0 && y > 0) cout << "Q2";
    else if (x < 0 && y < 0) cout << "Q3";
    else if (x > 0 && y < 0) cout << "Q4";

    return 0;
}