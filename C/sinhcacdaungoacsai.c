#include <stdio.h>

int n;
char p[16];

int is_valid() {
    int balance = 0;
    for (int i = 0; i < p[i]; ++i) {
        if (balance < 0 || balance > n) return 1;
        if (p[i] == '(') ++balance;
        else --balance;
    }
    return balance != 0;
}

void generate(int pos, int left, int right) {
    if (left + right > 0) {
        if (left > 0) {
            p[pos] = '(';
            generate(pos + 1, left - 1, right);
        }
        if (right > 0) {
            p[pos] = ')';
            generate(pos + 1, left, right - 1);
        }
        return;
    }
    if (is_valid()) printf("%s\n", p);
}

int main() {
    scanf("%d", &n);
    generate(0, n, n);
    return 0;
}