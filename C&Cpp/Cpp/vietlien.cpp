#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> solve(const string& s) {
	if (s.empty()) {
		return {""};
	}
	vector<vector<string>> dp(s.length() + 1);
	dp[0] = {""};
	for (int i = 1; i <= s.length(); ++i) {
		if (stoi(s.substr(i - 1, 1)) > 0) {
			for (const string &result: dp[i - 1]) {
				dp[i].push_back(result + static_cast<char>(stoi(s.substr(i - 1, 1)) + 'a' - 1));
			}
		}
		if (i != 1 && 10 <= stoi(s.substr(i - 2, 2)) && stoi(s.substr(i - 2, 2)) <= 26) {
			for (const auto &result: dp[i - 2]) {
				dp[i].push_back(result + static_cast<char>(stoi(s.substr(i - 2, 2)) + 'a' - 1));
			}
		}
	}
	return dp[s.length()];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	vector<string> result = solve(s);
	for (const string &str: result) {
		cout << str << "\n";
	}
	return 0;
}

