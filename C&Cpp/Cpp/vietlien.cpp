#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> solve(const std::string& s) {
	if (s.empty()) {
		return {""};
	}
	std::vector<std::vector<std::string>> dp(s.length() + 1);
	dp[0] = {""};
	for (int i = 1; i <= s.length(); ++i) {
		if (std::stoi(s.substr(i - 1, 1)) > 0) {
			for (const std::string &result: dp[i - 1]) {
				dp[i].push_back(result + static_cast<char>(std::stoi(s.substr(i - 1, 1)) + 'a' - 1));
			}
		}
		if (i != 1 && 10 <= std::stoi(s.substr(i - 2, 2)) && std::stoi(s.substr(i - 2, 2)) <= 26) {
			for (const auto &result: dp[i - 2]) {
				dp[i].push_back(result + static_cast<char>(std::stoi(s.substr(i - 2, 2)) + 'a' - 1));
			}
		}
	}
	return dp[s.length()];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::string s;
	std::cin >> s;
	std::vector<std::string> result = solve(s);
	for (const std::string &str: result) {
		std::cout << str << "\n";
	}
	return 0;
}


// code by duck it1
