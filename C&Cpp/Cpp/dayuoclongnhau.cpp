#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<ll> solve(ll n) {
	vector<ll> result = {n};
	for (ll i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			n /= i;
			result.push_back(n);
		}
	}
	if (n > 1 && result.back() != n) {
		result.push_back(n);
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	vector<ll> result = solve(n);
	reverse(result.begin(), result.end());
	if (result[0] != 1) result.insert(result.begin(), 1);
	for_each(result.cbegin(), result.cend(), [](const ll &x) { cout << x << " "; });
	return 0;
}
