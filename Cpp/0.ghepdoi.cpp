#include<iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << std::min(a, b) << " " << (int)(abs(a - b) / 2);
    return 0;
}