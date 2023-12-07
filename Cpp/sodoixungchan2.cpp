#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string n;
    std::cin >> n;
    std::string s = n;
    std::reverse(s.begin(), s.end());
    std::cout << n + s;
    return 0;
}

// code by duck it1
