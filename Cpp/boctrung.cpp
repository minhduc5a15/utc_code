#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int eggs, stickers, toys;
    cin >> eggs >> stickers >> toys;
    if (stickers + toys == eggs) {
        cout << eggs;
    }
    else {
        cout << max(eggs - stickers, eggs - toys);
    }
    return 0;
}

