#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix_sum(const string &s, char c) {
	vector<int> prefix(s.size());
	prefix[0] = (s[0] == c) ? 1 : 0;
	for (int i = 1; i < s.size(); ++i) {
		prefix[i] = prefix[i - 1] + ((s[i] == c) ? 1 : 0);
	}
	return prefix;
}

int solve(const vector<int> &prefix, int a, int b) {
	return a > 1 ? prefix[b - 1] - prefix[a - 2] : prefix[b - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int t;
	cin >> t;
	vector<int> prefix[26];
	for (char c = 'a'; c <= 'z'; ++c) {
		prefix[c - 'a'] = prefix_sum(s, c);
	}
	for (int i = 0; i < t; ++i) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		cout << solve(prefix[c - 'a'], a, b) << ' ';
	}
	return 0;
}


// code by duck it1
