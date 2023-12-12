#include <iostream>
#include <unordered_map>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string s, x;
    std::unordered_map<std::string, bool> map;
    int n;
    std::getline(std::cin, s);
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        map[x] = true;
    }
    std::stringstream si(s);
    while (si >> x) {
        if (map[x]) {
            std::cout << std::string(x.size(), '*') << " ";
        }
        else {
            std::cout << x << " ";
        }
    }
    return 0;
}


// code by duck it1
