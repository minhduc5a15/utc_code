#include <stdio.h>
#include <math.h>
#define ll long long

int square_number(ll n) {
    ll r = sqrt(n);
    return r * r == n;
}

int find_x(ll n) {
    int k = sqrt(n);
    for (int i = 1; i * i <= k; ++i) {
        if (n % i == 0) {
            ll dlt = 1 + 4 * (n / i);
            if (square_number(dlt)) {
                return (sqrt(dlt) - 1) / 2;
            }
        }
    }
    return 0;
}

void solve(ll n) {
    printf("1 ");
    int k = cbrt(n) + 1;
    for (int i = 2; i <= k; ++i) {
        if (n % (i * (i + 1)) == 0) {
            printf("%d ", i);
        }
    }
    int d = find_x(n);
    if (d > k) {
        printf("%d\n", d);
    }
    else {
        printf("\n");
    }
    return;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        if (n & 1) printf("-1\n");
        else solve(n);
    }
    return 0;
}
