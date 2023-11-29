#include <iostream>
#include <string>
#include <vector>

std::vector<int> prefix_sum(std::string s, char c) {
    std::vector<int> prefix(s.size());
    prefix[0] = (s[0] == c) ? 1 : 0;
    for (int i = 1; i < s.size(); ++i) {
        prefix[i] = prefix[i - 1] + ((s[i] == c) ? 1 : 0);
    }
    return prefix;
}

int solve(std::vector<int>& prefix, int a, int b) {
    if (a > 1) {
        return prefix[b - 1] - prefix[a - 2];
    }
    else {
        return prefix[b - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string s;
    std::cin >> s;
    int t;
    std::cin >> t;
    std::vector<int> result;
    std::vector<int> prefix[26];
    for (char c = 'a'; c <= 'z'; ++c) {
        prefix[c - 'a'] = prefix_sum(s, c);
    }
    for (int i = 0; i < t; ++i) {
        int a, b;
        char c;
        std::cin >> a >> b >> c;
        result.push_back(solve(prefix[c - 'a'], a, b));
    }
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    return 0;
}
