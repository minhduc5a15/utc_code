#include <iostream>

void checkTriangle(int a, int b, int c) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        std::cout << "KHONG PHAI TAM GIAC";
    }
    else if (a == b || a == c || b == c) {
        std::cout << "TAM GIAC CAN";
    }
    else if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) {
        std::cout << "TAM GIAC VUONG";
    }
    else {
        std::cout << "TAM GIAC THUONG";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int a, b, c;
    std::cin >> a >> b >> c;
    checkTriangle(a, b, c);
    return 0;
}

// code by duck it1
