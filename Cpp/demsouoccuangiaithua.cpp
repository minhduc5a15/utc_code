#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007
#define ll long long

using namespace std;


int total_pow(int n, int p) {
	int res = 1;
	int k = log(n) / log(p);
	for (int i = 1; i <= k; ++i) {
		res += n / pow(p, i);
	}
	return res;
}

vector<int> Sieve_of_Eratosthenes(int n) {
	vector<bool> prime(n + 1, true);
	int p = 2;
	while (p * p <= n) {
		if (prime[p]) {
			for (int i = p * p; i <= n; i += p) {
				prime[i] = false;
			}
		}
		++p;
	}
	prime[0] = false;
	prime[1] = false;
	vector<int> primes;
	for (p = 2; p <= n; ++p) {
		if (prime[p]) {
			primes.push_back(p);
		}
	}
	return primes;
}

ll solve(int n) {
	ll res = 1;
	vector<int> primes = Sieve_of_Eratosthenes(n);
	for (int prime: primes) {
		res = (res * total_pow(n, prime)) % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}


// code by duck it1
