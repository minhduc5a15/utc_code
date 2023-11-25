#include <iostream>
using namespace std;

int main() {
	int eggs, stickers, toys;
	cin >> eggs >> stickers >> toys;

	if (stickers + toys == eggs) cout << eggs;
	else cout << max(eggs - stickers, eggs - toys);

	return 0;
}