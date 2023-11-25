#include <stdio.h>
#include <math.h>
#define MAX_N 20

double calc(float n, int m) {
    return pow(n, m) / (tgamma(m + 1) * m);
}

double f(float a, float b) {
    double res = 0;
    for (int i = 1; i <= MAX_N; ++i) {
        int d = i * 2 - 1;
        int op = pow(-1, i & 1);
        res += op * (calc(a, d) - calc(b, d));
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        float a, b;
        scanf("%f %f", &a, &b);
        printf("%.6f\n", round(f(a, b) * 1e6) / 1e6);
    }
    return 0;
}
