#include <iostream>
#include <string>
#include <vector>
#define ll long long

const int MOD = 1000000007;
int solve(std::string s) {
    std::vector <ll> count(10, 0);
    int temp = 0;
    for (char &c : s) {
        temp = (temp + (c - '0')) % 9;
        ++count[temp];
    }
    int result = count[0];
    for (int i = 0; i < 9; ++i) result = (result + ((count[i] * (count[i] - 1)) / 2) % MOD) % MOD;
    
    return result;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string s;
    std::cin >> s;
    std::cout << solve(s);
    return 0;
}

// code by duck it1
