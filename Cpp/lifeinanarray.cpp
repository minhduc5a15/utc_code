#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, count = 0;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    for (char c: s) {
        if (c == '1') ++count;
    }
    if (count % 2 == 0) std::cout << s;
    else {
        if (n % 2 == 0 && ((int) s.size() - count) & 1) std::cout << s;
        else {
            for (char c: s) {
                if (c == '1') std::cout << '0';
                else std::cout << '1';
            }
        }
    }
    return 0;
}

