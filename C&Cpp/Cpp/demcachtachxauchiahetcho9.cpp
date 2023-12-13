#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define MOD 1000000007
using std::cin;
using std::cout;
using std::ios_base;
int solve(const std::string &s) {
	std::vector<ll> count(10, 0);
	int temp = 0;
	for (const char &c: s) {
		temp = (temp + (c - '0')) % 9;
		++count[temp];
	}
	int result = count[0];
	for (int i = 0; i < 9; ++i) {
        result = (result + ((count[i] * (count[i] - 1)) / 2) % MOD) % MOD;
    }

	return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	std::string s;
	cin >> s;
	cout << solve(s);
	return 0;
}

